#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
 int main(int argc, char *argv[])
 {
    //argc-1 参数个数，argv[0]文件本身，argv[1···n-1]参数 
 
    if( argc == 3 ){
        //argv[0]WordCount，argv[1]控制参数“-c”或“-w”，argv[2]文件名(test.c) 
        
		//打开文件 (test.c)
        //char data;
        FILE *fp = fopen(argv[2],"r");
         
        if(!fp){//无法打开文件 
            printf("无法打开文件！！！");
            return -1;
        }        
         
        if( !strcmp(argv[1],"-c") ){//控制参数与“-c”相等，统计字符个数 
            char c; //临时存放
            int c_count = 0;//字符个数为0 
            c = fgetc(fp);//将指针fp所指的字符存放在c中 
            while( c != EOF ){
                //文件没有遍历完 
                c = fgetc(fp);
                c_count++;//统计字符个数，存放一次，个数加一
            }
            printf("字符数：%d\n",c_count);   
         }
         
        else if( !strcmp(argv[1],"-w") ){//控制参数与“-w”相等，统计单词个数 
        	char w;//临时存放
            int w_count = 0;//单词个数为0 
            w = fgetc(fp);//将指针fp所指的字符存放在w中
            while( w != EOF){
            	//文件没有遍历完 
                if( (w >='a' && w <='z') || ( w >='A' && w <='Z') ){
                    while( (w >='a' && w <='z') || ( w >='A' && w <='Z')  )
                    {
                    	w =fgetc(fp);
					} 
                    w_count++;//统计字符个数
                    w =fgetc(fp);    
                }
                else
                    w =fgetc(fp);
            }
            printf("单词数：%d\n",w_count);
        }
        
        else{
            printf("控制参数只能为-c或-w");
        }
        //int n=fclose(fp);
    }
    else{
    	printf("输入格式错误，应该有三个参数\n");
    	printf("格式如下：WordCount.exe [parameter] [input_file_name]\n");
    }
    system("pause");
    return 0;
 }

