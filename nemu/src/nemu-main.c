#include <common.h>
void init_monitor(int, char *[]);
void am_init_monitor();
void engine_start();
int is_exit_status_bad();

//#define CONFIG_TARGET_AM

int main(int argc, char *argv[]) {
  /* Initialize the monitor. */
// ( 59 ) + ( ( ( 4 - 94 - ( ( ( 12 ) ) ) ) ) ) * ( ( ( 10 ) ) * 56 + ( ( 37 ) ) )

/*
	for(int i = 0; i < argc / 2 ; i++)
	{
		int ans;
		sscanf(argv[i * 2 + 1],"%d",&ans);
		int output;
		bool sucs=1;
		printf("%s\n",argv[i * 2 + 2]);
		output = expr(argv[i * 2 + 1], &sucs);
		printf("ans:%d output:%d \n", ans, output);
	}

*/

#ifdef CONFIG_TARGET_AM
  am_init_monitor();
#else
  init_monitor(argc, argv);
#endif

  /* Start engine. */
/*	for(int i=2; i < argc; i++)
	{
		char tmp[65536] = {0};
		word_t ans=0 ,exout;
		sscanf(argv[i],"%s",tmp);
		bool sucs = true;
		exout = expr(tmp, &sucs);
		if(sucs)
			printf("%d %d %d\n",ans,exout,exout == ans);
		else
			printf("wrong\n");
	}
*/
	engine_start();

	return is_exit_status_bad();
	
  }
