#include <cstdlib>
#include <iostream>
#include<iomanip> 

using namespace std;

struct fcfs{   //�����ȷ����㷨�����￪ʼ 
	char name[10];    
	float arrivetime;    
	float servicetime;    
	float starttime;    
	float finishtime;    
	float zztime;    
	float dqzztime;    
};   //����һ���ṹ�壬�����������һ��������ص���Ϣ 
 
fcfs a[100];  
  
void input(fcfs *p,int N)    
{ 
	int i;   
    cout<<endl; 
	printf("    ����������̵�            ����   ����ʱ��   ����ʱ��:  (����: a 0 100)\n\n");    
	for(i=0;i<=N-1;i++)    
	{    
		printf("     �����������%d����Ϣ:\t",i+1);
		scanf("\t\t\t%s%f%f",&p[i].name,&p[i].arrivetime,&p[i].servicetime);   
		
	}    
   
}    
void Print(fcfs *p,float arrivetime,float servicetime,float starttime,float finishtime,float zztime,float dqzztime,int N)    
{
	int k;      
    printf("\n\n���������ȷ����㷨�Ժ�������е�˳����: ");    
    printf("%s",p[0].name);    
	for(k=1;k<N;k++)    
	{
		printf("-->%s",p[k].name);    
	}   
     cout<<endl; 
	printf("\n   ������̵�����Ϣ:\n");    
    printf("\t������  ����ʱ��  ����ʱ��  ��ʼʱ��  ����ʱ��  ��תʱ��  ��Ȩ��תʱ��\n");    
   
     for(k=0;k<=N-1;k++)    
     {
		 printf("\t%s\t%-.2f\t  %-.2f\t   %-.2f\t       %-.2f\t %-.2f\t  %-.2f\n",p[k].name,p[k].arrivetime,
			 p[k].servicetime,p[k].starttime,p[k].finishtime,p[k].zztime,p[k].dqzztime);
     }      
     getchar();    //�˴�����Ҫ���������������Ϳ�������ʾ���������������Կ����Ľ��ֻ��һ��������һ����� 
}
  
   
void sort(fcfs *p,int N)  //����  
{    
     for(int i=0;i<=N-1;i++)    
         for(int j=0;j<=i;j++)    
             if(p[i].arrivetime<p[j].arrivetime)    
             {    
                 fcfs temp;    
                 temp=p[i];    
                 p[i]=p[j];    
                 p[j]=temp;    
             }    
}     
void deal(fcfs *p, float arrivetime,float servicetime,float starttime,float finishtime,float &zztime,float &dqzztime,int N)   //���н׶�   
{
	int k;    
    for(k=0;k<=N-1;k++)    
     {    
         if(k==0)    
		 {     
			 p[k].starttime=p[k].arrivetime;    
			 p[k].finishtime=p[k].arrivetime+p[k].servicetime;}    
   
         else   
		 {    
			 p[k].starttime=p[k-1].finishtime;    
             p[k].finishtime=p[k-1].finishtime+p[k].servicetime;}    
     }    
   
     for(k=0;k<=N-1;k++)    
     {    
		 p[k].zztime=p[k].finishtime-p[k].arrivetime;    
		 p[k].dqzztime=p[k].zztime/p[k].servicetime;    
         
     }    
}       
void FCFS(fcfs *p,int N)    
{    
     float arrivetime=0,servicetime=0,starttime=0,finishtime=0,zztime=0,dqzztime=0;    
     sort(p,N);    
     deal(p,arrivetime,servicetime,starttime,finishtime,zztime,dqzztime,N);    
     Print(p,arrivetime,servicetime,starttime,finishtime,zztime,dqzztime,N);    
     getchar();       
}  //�����ȷ����㷨���˽��� 
struct sjf{//��̽������ȵ����㷨�����￪ʼ 
	char name[10];
	float arrivetime;  //����ʱ��
	float servicetime;  //����ʱ��
	float starttime;    //��ʼʱ��
	float finishtime;   //���ʱ��

};
sjf a1[100];


void input(sjf *p,int N1)//������Ϣ����
{ 
	int i;
	cout<<endl;
    printf("    ����������̵�            ����   ����ʱ��   ����ʱ��:  (����: a 0 100)\n");
    for(i=0;i<=N1-1;i++)
	{ 
       printf("     �����������%d����Ϣ:\t",i+1);
       scanf("\t\t\t%s%f%f",&p[i].name,&p[i].arrivetime,&p[i].servicetime);
	}
}


void Print(sjf *p,float arrivetime,float servicetime,float starttime,float finishtime,int N1)//���ս�����
{
     int k;
     printf("\n\t������̽������ȵ����㷨�Ժ���̵ĵ���˳��Ϊ:");
     printf("%s",p[0].name);
     for(k=1;k<N1;k++)
	 {printf("-->%s",p[k].name);} 
	 cout<<endl; 
     printf("\n�������̾��������Ϣ����:\n");
     printf("\n\t������\t����ʱ��\t����ʱ��\t��ʼʱ��\t���ʱ��\n");
    
     for(k=0;k<=N1-1;k++)
     {
                        printf(" \t%s\t  %-.2f\t\t  %-.2f\t\t  %-.2f\t\t  %-.2f\t\n",p[k].name,p[k].arrivetime,
		 p[k].servicetime,p[k].starttime,p[k].finishtime);
      }
         
		  getchar();
   
}
void sort(sjf *p,int N1)//����
{
     for(int i=0;i<=N1-1;i++)
         for(int j=0;j<=i;j++)
             if(p[i].arrivetime<p[j].arrivetime)
             {
                 sjf temp;
                 temp=p[i];
                 p[i]=p[j];
                 p[j]=temp;
             }
}
void deal(sjf *p, float arrivetime,float servicetime,float starttime,float finishtime,int N1)//���н׶�
{ int k;
    for(k=0;k<=N1-1;k++)
     {
         if(k==0)
            { 
    p[k].starttime=p[k].arrivetime;
     p[k].finishtime=p[k].arrivetime+float(p[k].servicetime)/60;}
         else
           {
    p[k].starttime=p[k-1].finishtime;
             p[k].finishtime=p[k-1].finishtime+float(p[k].servicetime)/60;}
     }
   
} 
void sjff(sjf *p,int N1)
{
	    float arrivetime=0,servicetime=0,starttime=0,finishtime=0;
        sort(p,N1);
        for(int m=0;m<N1-1;m++)
        {if(m==0)
            p[m].finishtime=p[m].arrivetime+float(p[m].servicetime)/60;
         else
            p[m].finishtime=p[m-1].finishtime+float(p[m].servicetime)/60;
  
         int i=0;
         for(int n=m+1;n<=N1-1;n++)
		 {
			 if(p[n].arrivetime<=p[m].finishtime)
             i++;
		 }
         float min=p[m+1].servicetime;
         int next=m+1;
         for(int k=m+1;k<m+i;k++)
         {
          if(p[k+1].servicetime<min)
            {min=p[k+1].servicetime;
            next=k+1;}
            
         }
            sjf temp;
            temp=p[m+1];
            p[m+1]=p[next];
            p[next]=temp;
        }
        
        deal(p,arrivetime,servicetime,starttime,finishtime,N1);
   
        Print(p,arrivetime,servicetime,starttime,finishtime,N1);
         getchar();
}//��̽������ȵ����㷨��������� 
char menu()//������������Ϣ�ĺ��� 
{
     char cse1;
     while(1)
     {
             system("cls");
             fflush(stdin);
             cout<<endl; 
             cout<<endl; 
             cout<<"\t"<<"|| <<<<<<<<<<<<��<<<<<<<<<<<  >>>>>>>>>>>>ӭ>>>>>>>>>>> ||"<<endl ;
             cout<<"\t"<<"||                                                      ||"<<endl ;
             cout<<"\t"<<"||"<<"\t  ʵ �� һ     �� �� �� �� �� �� ʵ ��"<<"\t\t"<<"||"<<endl; 
             cout<<"\t"<<"||                                                      ||"<<endl ;
             cout<<"\t"<<"||"<<"\t\t  1.�����ȷ�������㷨  "<<"\t\t"<<"||"<<endl;
             cout<<"\t"<<"||                                                      ||"<<endl ;
             cout<<"\t"<<"||"<<"\t\t  2.��̽������ȵ����㷨"<<"\t\t"<<"||"<<endl; 
             cout<<"\t"<<"||                                                      ||"<<endl ;
             cout<<"\t"<<"|| <<<<<<<<<<<<<<<<<<<<<<<<<��>>>>>>>>>>>>>>>>>>>>>>>>> ||"<<endl ;
             cout<<endl;
             cout<<endl;
             cout<<"\t\t    ����������ѡ��1/2����";
             cse1=getchar();           
             if(cse1<'1'||cse1>'2')
                                   cout<<"��������д�"<<endl;                                 
             else
                                   break; 
     }
	 return cse1;
     
}
int main(int argc, char *argv[])
{
    while(1)
    {
            switch(menu())
            {
                case '1':
                           int N;    
                           cout<<endl;
                           cout<<endl; 
                           printf("\t\t<<---!!!@@@�����ȷ�������㷨@@@!!!--->>\n");    
                           cout<<endl;
                           printf("���������Ŀ:");    
                           scanf("%d",&N);    
                           input(a,N);    
                           FCFS(a,N); 
                
                
                case '2':      
                           int N1;
                           cout<<endl;
                           cout<<endl; 
                           printf("\t\t<<---!!!@@@��̽������ȵ����㷨@@@!!!--->>\n");
                           cout<<endl;
                           printf("���������Ŀ: ");
                           scanf("%d",&N1);
                           input(a1,N1);
                           sjf *b=a1;
                           sjf *c=a1;
                           sjff(b,N1);
                           getchar();   
            }
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
