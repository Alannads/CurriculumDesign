#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define  HEAD printf("\t|%-10s%-8s%-9s%-5s%-10s%-5s%-5s%-5s%-5s%-12s%-5s|\n","ѧ��","����","רҵ","�༶","��Ԣ��","����","��λ","�Ա�","���","�ֻ���","����")
/*
		�����¼ 
		�����¼��Ϣ 
*/
typedef struct EN{//���û������� 
	char userName1[10];
	char passWorld1[10];
}EN;
void enter();
void encryption(char passWorld[])//����
{
	int i; 
	for(i=0;i<strlen(passWorld);i++)
	{
		passWorld[i]+=20;
	} 
} 
void  sign_in(char userName[],char passWorld[])//ע��
{
	FILE *fp;
	int flag=0;
	char userName1[10];
	char passWorld1[10];
	printf("\tע��(�û����������9λ)\n");
	printf("\t�û���:");
	fflush(stdin);
	gets(userName);
	printf("\t����:");
	gets(passWorld);
	if((fp=fopen("enter.txt","rt"))==NULL)
	{
		exit(0);
	}
	while(!feof(fp))
	{
		fscanf(fp,"%s %s",userName1,passWorld1);
		if(!strcmp(userName,userName1))
		{
			printf("�û����ظ�\n");
			flag=1;
			break;
		}
	}
	fclose(fp);
	if(flag==1)
	enter();
	else
	{
		if((fp=fopen("enter.txt","at"))==NULL)
		exit(0);
		encryption(passWorld);//����
		fprintf(fp,"%s %s\n",userName,passWorld);
	}
	fclose(fp);
	enter(); 
}
void alter()//ɾ�����Ϸ��û� 
{
	FILE *fp;
	int n=0;
	EN en[1000];
	fp=fopen("enter.txt","rt");
	if(fp==NULL)
	{
		printf("\t���ļ�ʧ��\n");
		exit(0);
	}
	while(!feof(fp))
	{
		fscanf(fp,"%s %s",en[n].userName1,en[n].passWorld1);
		n++;
	}
	//printf("��С%d\n",--n);
	printf("\t%-8s\t%-8s\n","�û���","����");
	int i;
	for(i=0;i<n;i++)
	{
		printf("\t%-8s\t%-8s\n",en[i].userName1,en[i].passWorld1);
	}
	fclose(fp);
	printf("\t������Ҫɾ�����û���\n");
	printf("\t�û���:");
	char ch[10];
	printf("\t");
	scanf("%s",ch);
	for(i=0;strcmp(ch,en[i].userName1);i++){}
	int k=i;
	for(i=k;i<n-1;i++)
	{
		en[i]=en[i+1];
	}
	n--;
//	for(i=0;i<n;i++)
//	{
//		printf("%-8s\t%-8s\n",en[i].userName1,en[i].passWorld1);
//	}
	fp=fopen("enter.txt","wt");
	if(fp==NULL)
	{
		printf("\t���ļ�ʧ��\n");
		exit(0);
	}
	for(i=0;i<n;i++)
	{
		fprintf(fp,"%s %s\n",en[i].userName1,en[i].passWorld1);
	}
	fclose(fp);	
}
void enter()		//��¼��� 
{
	printf("\t=================================\n"); 
	printf("\t|\t��¼:\t\t\t|\n");
	printf("\t=================================\n");
	FILE *fp;
	int i;
	
	printf("\t1.����Ա\t2.��¼\n");
	char userName[10];
	char passWorld[10];
	char userName1[10];
	char passWorld1[10];
	int choice;
	printf("\t");
	scanf("%d",&choice);
	int flag=0;
	switch(choice)
	{
		case 1:{        //����Ա��ע���û���ɾ�� 
			char adm[10]; 
			printf("\t����Ȩ����\n");
			printf("\t");
			scanf("%s",adm);
			if(strcmp(adm,"12"))
			{
				printf("\tȨ�������\n");
				enter();
			}
			printf("\t");
			printf("1.ע��\t2.�޸�\n");
			int j;
			printf("\t");
			scanf("%d",&j);
			switch(j)
			{
				case 1:{
					sign_in(userName,passWorld);
					break;
				}
				case 2:{
					int flag1=0;
					do
					{
						alter();
						flag1=0;
						printf("\t�Ƿ����ɾ����1.��  2.��\n");
						printf("\t");
						scanf("%d",&flag1);
					}
					while(flag1==1);
					enter();
					break;
				}
				default:{
					break;
				}
			}			
			break;
		}
		case 2:{     //�û���¼ 
			printf("\t��¼\n");
			printf("\t�û���:");
			fflush(stdin);
			printf("\t");
			gets(userName);
			printf("\t����:");
			printf("\t");
			gets(passWorld);
			if((fp=fopen("enter.txt","rt"))==NULL)
			{
				exit(0);
			}
			while(!feof(fp))
			{
				fscanf(fp,"%s %s",userName1,passWorld1);
				encryption(passWorld);//����
				if(!strcmp(userName,userName1)&&!strcmp(passWorld,passWorld1))
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				printf("\t�����û������벻ƥ����ߴ���\n");
				enter();
			}
			printf("\t�ɹ�\n");
			break;
		}
		default:{
			printf("����ѡ�񲻷��ϸ�ʽ\n");
			break;
		}
	}
}
/*
			�洢���� 
			�������� 
*/

typedef struct stu{  //������Ϣ 
	char dorm[50];
	int dorm_num;
	int dorm_num_id;
	char id[10];
	char name[10];
	int banji;
	char major[20];
	int age;
	int enUniversity;
	char number[12];
	char sex[3]; 
	struct stu *next;
}stu;
void print(stu *head);
void interface()//������ 
{
	printf("\n\n");
	printf("\t---------------------------------------------------------\n"); 
	printf("\t|\t\t��ӭʹ��������Ϣ����ϵͳ\t\t|\n");
	printf("\t---------------------------------------------------------\n");
	/*
		����¼�� 
	*/ 
	printf("\t|\t\t\t1-¼������\t\t\t|\n"); 
	/*
		������ɾ�Ĳ� 
	*/ 
	printf("\t|\t\t\t2-��������\t\t\t|\n");  
	printf("\t|\t\t\t3-����ɾ��\t\t\t|\n");
	printf("\t|\t\t\t4-�����޸�\t\t\t|\n");
	printf("\t|\t\t\t5-���ݲ�ѯ\t\t\t|\n");
	/*
		����ͳ�� 
	*/ 
	printf("\t|\t\t\t6-����ͳ��\t\t\t|\n");
	/*
		���� 
	*/ 
	printf("\t|\t\t\t7-���ݱ���\t\t\t|\n");
	printf("\t---------------------------------------------------------\n");
}
int find_id(char id[],stu *head)//ѧ�Ų���,�ظ�����0������1 
{
	stu *i;
	for(i=head->next;i!=NULL;i=i->next)
	{
		if(strcmp(id,i->id)==0)
		{
			printf("\tѧ���ظ�\n");
			return 0;
		}
	}
	return 1;
}
int find_check(stu *head,stu *p) //��������Ƿ���Ա,���Ϸ���1�������Ϸ���0 
{
	//print(head);   //���� 
	//printf("����\n");
	stu *i;
	for(i=head->next;i!=NULL;i=i->next)
	{
		if(!strcmp(p->dorm,i->dorm)&&(p->dorm_num_id==i->dorm_num_id)&&(p->dorm_num==i->dorm_num))
		{
			printf("\t������Ϣ�ظ�\n");
			return 0;
		}
	}
	return 1;
}
stu *creat()//�������� 
{
	
	stu *head,*end,*p;
	char id[10];
	head=NULL;
	head=(stu*)malloc(sizeof(stu));
	head->next=NULL;
	end=head;
	printf("\t����ѧ��:");
	fflush(stdin);
	gets(id);
	while(strlen(id)>0)
	{
		
		if(find_id(id,head))//ѧ�Ų���,�ظ�����0������1 
		{
			p=(stu*)malloc(sizeof(stu));
			strcpy(p->id,id);
			printf("\t��������:");	
			gets(p->name);
			printf("\t���빫Ԣ����:");			
			scanf("%s",p->dorm);
			printf("\t������������:");
			scanf("%d",&p->dorm_num);
			printf("\t���봲λ��:");
			scanf("%d",&p->dorm_num_id);
			if(find_check(head,p))  //��������Ƿ���Ա,���Ϸ���1�������Ϸ���0 
			{		
				printf("\t�ֻ���:");
				fflush(stdin);
				gets(p->number); 
				printf("\t����:");
				scanf("%d",&p->age); 
				printf("\t�Ա�:");
				scanf("%s",p->sex); 
				printf("\tרҵ�༶:");
				scanf("%s %d",p->major,&p->banji);
				printf("\t������ѧ���:");
				scanf("%d",&p->enUniversity);
				end->next=p;
				end=p;
				p->next=NULL;
			} 	
		}
		printf("\t����ѧ��:");
		fflush(stdin);
		gets(id);
	}
	return head;
}
void print(stu *head)//�����ӡ��� 
{
	
	stu *i;
	for(i=head->next;i!=NULL;i=i->next)
	{
		printf("\t|%-10s%-8s%-9s%-5d%-10s%-5d%-5d%-5s%-5d%-12s%-5d|\n",i->id,i->name,i->major,i->banji,i->dorm,i->dorm_num,i->dorm_num_id,i->sex,i->age,i->number,i->enUniversity);
	}
}
stu *write_linked()  //�ļ��������� 
{
	
	FILE *fp;
	fp=fopen("student.txt","rt");
	stu *i;
	stu *head;
	head=NULL;
	head=(stu*)malloc(sizeof(stu));
	stu *end,*p;
	end=head;
	while(!feof(fp))
	{
		p=(stu*)malloc(sizeof(stu));
		fread(p,sizeof(stu),1,fp);
		fgetc(fp);
		end->next=p;
		end=p;
		p->next=NULL;
	}
	fclose(fp);
	return head; 
}
void write_file(stu *head)  //�����������ļ� 
{
	FILE *fp;
	fp=fopen("student.txt","wt");
	stu *i;
	for(i=head->next;i!=NULL;i=i->next)
	{
		fwrite(i,sizeof(stu),1,fp);
		if(i->next!=NULL)
		fputc('\n',fp);
	}
	fclose(fp);
	printf("���\n");
}
void header()//���ݱ�ͷ
{
	printf("\t---------------------------------------------------------------------------------\n");
	HEAD;
	printf("\t---------------------------------------------------------------------------------\n");
}
void exchange_num(int *x,int *y)//����int 
{
	int t=*x;
	*x=*y;
	*y=t;
}
void exchange_string(char a[],char b[])//�����ַ��� 
{
	char t[20];
	strcpy(t,a);
	strcpy(a,b);
	strcpy(b,t);
}
void exchange(stu *ec1,stu *ec2) //����stu�ṹ������ 
{
	exchange_num(&ec1->age,&ec2->age);
	exchange_num(&ec1->banji,&ec2->banji);
	exchange_string(ec1->dorm,ec2->dorm);
	exchange_num(&ec1->dorm_num,&ec2->dorm_num);
	exchange_num(&ec1->dorm_num_id,&ec2->dorm_num_id);
	exchange_string(ec1->id,ec2->id);
	exchange_num(&ec1->enUniversity,&ec2->enUniversity);
	exchange_string(ec1->major,ec2->major);
	exchange_string(ec1->name,ec2->name);
	exchange_string(ec1->number,ec2->number);
	exchange_string(ec1->sex,ec2->sex);
}
void sort(stu *head) //���ݹ�Ԣ ���� ��λ ���� 
{
	stu *i,*j;
	for(i=head->next;i!=NULL;i=i->next)
	{
		for(j=i->next;j!=NULL;j=j->next)
		{
			if(strcmp(i->dorm,j->dorm)>0)
			{
				exchange(i,j);
			}
		}
	}
	
	for(i=head->next;i!=NULL;i=i->next)
	{
		for(j=i->next;j!=NULL;j=j->next)
		{
			if(!strcmp(i->dorm,j->dorm)&&i->dorm_num>j->dorm_num)
			{
				exchange(i,j);
			}
		}
	}
	
	for(i=head->next;i!=NULL;i=i->next)
	{
		for(j=i->next;j!=NULL;j=j->next)
		{
			if(strcmp(i->dorm,j->dorm)==0&&i->dorm_num==j->dorm_num&&i->dorm_num_id>j->dorm_num_id)
			{
				exchange(i,j);
			}
		}
	}
	
}
int main() 
{	
	//enter();//��¼ 
	system("cls");
	printf("\t��½�ɹ�\n");
	int choice;
	while(1)
	{
		interface();
		stu *head;
		printf("\t����1~7��");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:{//¼����Ϣ 
				head=creat();//��������
				//print(head); 
				write_file(head);//д���ļ� 
				
				break;
			}
			case 2:{//���� 
				
				break;
			}
			case 3:{ //��ѧ��ɾ�� 
				
				break;
			}
			case 4:{//�İ�ѧ�� 
				
				break;
			}
			case 5:{//�飬�����������ᣬѧ�� 
				
				break;
			}
			case 6:{ //ͳ�ƣ���������ÿ������������һ��¥���� 
				
				break;
			}
			case 7:{//���� 
				head=write_linked();
				header(); 
				sort(head);
				print(head);
				printf("\t---------------------------------------------------------------------------------\n");
				break;
			}
			default :{
				//system("cls");
				printf("\t->��������,��������<-\n");
				break;
			}
		}
		printf("\t�����������");
		fflush(stdin);
		getchar();
		system("cls");
	}
	
	
	
}









