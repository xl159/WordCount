#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
 int main(int argc, char *argv[])
 {
    //argc-1 ����������argv[0]�ļ�����argv[1������n-1]���� 
 
    if( argc == 3 ){
        //argv[0]WordCount��argv[1]���Ʋ�����-c����-w����argv[2]�ļ���(test.c) 
        
		//���ļ� (test.c)
        //char data;
        FILE *fp = fopen(argv[2],"r");
         
        if(!fp){//�޷����ļ� 
            printf("�޷����ļ�������");
            return -1;
        }        
         
        if( !strcmp(argv[1],"-c") ){//���Ʋ����롰-c����ȣ�ͳ���ַ����� 
            char c; //��ʱ���
            int c_count = 0;//�ַ�����Ϊ0 
            c = fgetc(fp);//��ָ��fp��ָ���ַ������c�� 
            while( c != EOF ){
                //�ļ�û�б����� 
                c = fgetc(fp);
                c_count++;//ͳ���ַ����������һ�Σ�������һ
            }
            printf("�ַ�����%d\n",c_count);   
         }
         
        else if( !strcmp(argv[1],"-w") ){//���Ʋ����롰-w����ȣ�ͳ�Ƶ��ʸ��� 
        	char w;//��ʱ���
            int w_count = 0;//���ʸ���Ϊ0 
            w = fgetc(fp);//��ָ��fp��ָ���ַ������w��
            while( w != EOF){
            	//�ļ�û�б����� 
                if( (w >='a' && w <='z') || ( w >='A' && w <='Z') ){
                    while( (w >='a' && w <='z') || ( w >='A' && w <='Z')  )
                    {
                    	w =fgetc(fp);
					} 
                    w_count++;//ͳ���ַ�����
                    w =fgetc(fp);    
                }
                else
                    w =fgetc(fp);
            }
            printf("��������%d\n",w_count);
        }
        
        else{
            printf("���Ʋ���ֻ��Ϊ-c��-w");
        }
        //int n=fclose(fp);
    }
    else{
    	printf("�����ʽ����Ӧ������������\n");
    	printf("��ʽ���£�WordCount.exe [parameter] [input_file_name]\n");
    }
    system("pause");
    return 0;
 }

