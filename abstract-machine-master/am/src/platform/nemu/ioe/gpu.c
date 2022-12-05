#include <am.h>
#include <nemu.h>
#include<klib.h>

#define SYNC_ADDR (VGACTL_ADDR + 4)

  static AM_GPU_CONFIG_T config;

void __am_gpu_init() {
  //int i;
  uint32_t hei_wei = inl(VGACTL_ADDR);
  uint32_t w = hei_wei >> 16;  
  uint32_t h = hei_wei & 0xffff;  
  config.width = w;
  config.height = h;

  uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
  //for (i = 0; i < w * h; i ++) fb[i] = i;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      fb[i*w+j] = ((((i%255<<8)+i%255)<<8)+i%255);
    }
  }
  outl(SYNC_ADDR, 1);
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  cfg->present = true;
  cfg->has_accel = false;
  cfg->vmemsz = 0;
  cfg->height=config.height;
  cfg->width = config.width;
}


void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl)
{
  if (ctl->sync) {
    outl(SYNC_ADDR, 1);
  }
  //printf("%d %d %d %d\n",ctl->x, ctl->y, ctl->w, ctl->h);
  if(ctl->pixels){
    uint32_t *fb = NULL;
    for(int i=0;i<ctl->h;i++)
    {
      fb = (uint32_t *)(FB_ADDR+(ctl->y+i)*config.width+ctl->x);
      //printf("fb start: (%d,%d)  end : ()\n", ctl->y+i, ctl->x ,ctl->y+i);
      for(int j=0;j<ctl->w;j++,fb++){
          *fb = *(uint32_t*)(ctl->pixels+i*ctl->w+j);
      }
    }
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
