//#define __LCOM_OPTIMIZED__
#include <lcom/lcf.h>
#include <lcom/proj.h>
#include <lcom/liblm.h>

#include "project/include/loopFuncs.h"


int main(int argc, char* argv[]) {

    lcf_set_language("EN-US");

    lcf_trace_calls("/home/lcom/labs/proj/src/trace.txt");

    lcf_log_output("/home/lcom/labs/proj/src/output.txt");

    if (lcf_start(argc, argv)) return 1;

    lcf_cleanup();

    return 0;
}


int(proj_main_loop)(int argc, char* argv[])
{   
    if(argc == 1){
        if(strcmp(argv[0], "main") == 0){
            return mainLoop();
        }else if(strcmp(argv[0], "sender") == 0){
            return senderLoop();
        }else{
            printf("Argument wrong\n");
            return 1;
        }
    }else{
        printf("Error number of arguments wrong\n");
        return 1;
    }
}

