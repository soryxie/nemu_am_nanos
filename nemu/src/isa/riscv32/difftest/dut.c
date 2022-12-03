#include <isa.h>
#include <cpu/difftest.h>
#include "../local-include/reg.h"

bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc) {
  for(int i=0;i<32;i++)
    if(cpu.gpr[i]._32 != ref_r->gpr[i]._32)
      return false;
  if(cpu.pc!=pc)
    return false;
  return true;
}

void isa_difftest_attach() {
}
