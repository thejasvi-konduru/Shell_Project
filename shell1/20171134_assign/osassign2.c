#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/dir.h>
#include<sys/param.h>
#include<pwd.h>
#include<grp.h>
#include<time.h>
#include<locale.h>
#include<langinfo.h>
#include<stdint.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<errno.h>
#include<sys/wait.h>
void display(void);
void loop(void);
char *read_line(void);
void command_ls1(char* args21);
char good[1000];
char good1[1000];
char good2[1000];
char how[1000];
char **split_line(char *line,char *seperator);
void command_cd(char s[]);
void command_ls(char* hoho);
char hostname[1024];
char q[100],r[100];
int l=-1,j,donkey=1;
char s='/';
char p='/';
int num=0;
int position=0;
struct stat sts;
char **args;
FILE* fp=NULL;
int duty;
int sum=0,many=0;
int bg;
char args2[100];
int PID;
int main()
{
	loop();
	return 0;
}
void display(void)
{
	gethostname(hostname,1024);
	printf("%s@%s:~$",getenv("USER"),hostname);
}
void loop(void)
{
	char *line;
	int i,length2,w,init=0,length=0,length1,k,count=0;
	long long int x;
	DIR *myDirectory;
	FILE* p;
	pid_t pid;
	char **args1;char **args3;
	display();
	while(2==2)
	{
		line=read_line();
		args=split_line(line," \t");
		if(!strcmp(args[0],"pinfo"))
		{many++;
			if(args[1]==NULL)
			{
				x=getpid();
				printf("PID ---- %lld\n",x);
				FILE *f=fopen("/proc/self/stat","r");
				int status1;
				char state,status2[1000];
				fscanf(f,"%d %s %c",&status1,status2,&state);
				printf("Process Status -- ");
				printf("%c\n",state);
				fclose(f);

				long long int mem;
				FILE *f1=fopen("/proc/self/statm","r");
				fscanf(f1,"%lld",&mem);
				printf("Virtual Memory -- ");
				printf("%lld\n",mem);
				fclose(f1);

				char path[1000],link[1000000];
				strcpy(path,"/proc/self/exe");
				int len=readlink(path,link,sizeof(link));
				printf("Executable Path -- %s",link);
				printf("\n");
			}

			else
			{
				sprintf(how,"/proc/%s",args[1]);
				if(!(stat(how,&sts)== -1 && errno ==ENOENT))
				{
					printf("PID --- %s\n",args[1]);
					sprintf(good,"/proc/%s/stat",args[1]);
					FILE *f=fopen(good,"r");
					int status1;
					char state,status2[1000];
					fscanf(f,"%d %s %c",&status1,status2,&state);
					printf("Process Status -- ");
					printf("%c\n",state);
					fclose(f);

					long long int mem;
					sprintf(good1,"/proc/%s/statm",args[1]);
					FILE *f1=fopen(good1,"r");
					fscanf(f1,"%lld",&mem);
					printf("Virtual Memory -- ");
					printf("%lld\n",mem);
					fclose(f1);

					char path[1000],link[1000000];
					sprintf(good2,"/proc/%s/exe",args[1]);
					strcpy(path,good2);
					int len=readlink(path,link,sizeof(link));
					printf("Executable Path -- %s",link);
					printf("\n");
				}
				else 
					printf("Process with given ID does not exist");
			}
			printf("%s@%s:~/%s$",getenv("USER"),hostname,args2);
		}
	        //if(!strcmp(args[1],"~")){
     		//	printf("\n%s@%s:~$",getenv("USER"),hostname);
		//	for(int z=0;z<length;z++)
                  //                              args2[z]='\0';}
		if(!strcmp(args[0],"cd"))
		{many++;
			if(args2[0]!=0)
				strcat(args2,"/");
			strcat(args2,args[1]);
			myDirectory=opendir(args2);
		}
		if(!strcmp(args[0],"cd"))
		{many++;
			args1=split_line(args2,"/");
			if(!strcmp(args1[position-1],".."))
				count++;
			if(num==1)
			  printf("hi");
			
		    else{
			if(myDirectory==NULL)
				printf("Directory does not exists");
			else
			{
				if(position>0)
					printf("%s@%s:~/",getenv("USER"),hostname);
				if(position==0)
					printf("%s@%s:~",getenv("USER"),hostname);
				for(i=0;i<position;i=i+1)
				{
					length1=strlen(args1[i]);
					if(i==0)
						length=length1;
					else
						length=length+length1+1;
					for(w=init,j=0;w<length&&j<length1;w++,j++)
					{

						args2[w]=args1[i][j];
					}
					if(i!=position-1)
						args2[length]='/';
					init=init+length1+1;
				}
				if(!strcmp(args1[position-1],"..")&&count>0)
				{
					for(int z=0;z<length;z++)
						args2[z]='\0';
				}
				printf("%s",args2);
				printf("$");				
			}}
		}//}
		if(!strcmp(args[0],"pwd"))
		{many++;
			printf("%s",args2);
			printf("\n%s@%s:~/%s$",getenv("USER"),hostname,args2);
		}
		if(!strcmp(args[0],"ls"))
		{ many++;
			if(args2[0]==0){
				
				command_ls("/home/dell");}
			else{     
				command_ls(args2);}
			printf("\n%s@%s:~/%s$",getenv("USER"),hostname,args2);
		}
		if(!strcmp(args[0],"echo"))
		{many++;
			printf("\n");
			for(int z=1;z<position;z++)
				printf("%s ",args[z]);
			printf("\n%s@%s:~/%s$",getenv("USER"),hostname,args2);
		}
		if(many==0)
		{
			printf("Typed command cannot be executed");
			printf("\n%s@%s:~/%s$",getenv("USER"),hostname,args2);
		}
		//free(line);
		//}	//free(args);
		many=0;
       }

}
char *read_line(void)
{
	int bufsize=1024,position=0;
	char *buffer=malloc(sizeof(char)*bufsize);
	int c;
	while(2==2)
	{
		c=getchar();
		if(c==EOF||c=='\n')
		{
			buffer[position]='\0';
			return buffer;
		}
		else
			buffer[position]=c;
		position++;
		if(position>=bufsize)
		{
			bufsize=bufsize+1024;
			buffer=realloc(buffer,bufsize);
		}
	}
}
char **split_line(char *line,char *seperator)
{
	int bufsize=1024;
	position=0;
	char **tokens=malloc(bufsize*sizeof(char*));
	char *token;
	token=strtok(line,seperator);
	while(token!=NULL)
	{
		tokens[position]=token;
		if(!strcmp(token,"..")&&position>1)
			position=position-2;
		if(!strcmp(token,".")&&position>1)
			position=position-1;
		position++;
		if(position>=bufsize) 
		{
			bufsize=bufsize+1024;
			tokens=realloc(tokens,bufsize*sizeof(char*));
		}
		token=strtok(NULL,seperator);
	}
	tokens[position]=NULL;
	return tokens;
}
void command_ls(char* hoho)
{
	char dirname[10];
	char* filename[256];
	DIR* p;
	char* c=".";
	struct dirent *d;
	p=opendir(hoho);
	if(p==NULL)
	{
		perror("Cannot find directory");
		exit(-1);
	}
	while(d=readdir(p))
	{
		if(args[1]!=NULL)
		{
		if(!strcmp(args[1],"-a"))
			printf("%s\n",d->d_name);
		if(sum==1)
		  break;
		if(!strcmp(args[1],"-la"))
			command_ls1(args2);
		}
		else if(args[1]==NULL)
		{
			if(!strcmp(d->d_name,".")||!strcmp(d->d_name,".."))
			{}
			else if(strncmp(d->d_name,c,1))
			{
				printf("%s\n",d->d_name);
			}
		}

	}
	return;
}
static char perms_buff[30];
const char *get_perms(mode_t mode)
{
        char ftype='?' ;

        if (S_ISREG(mode)) ftype = '-';
        if (S_ISLNK(mode)) ftype = 'l';
        if (S_ISDIR(mode)) ftype = 'd';
        if (S_ISBLK(mode)) ftype = 'b';
        if (S_ISCHR(mode)) ftype = 'c';
        if (S_ISFIFO(mode)) ftype = '|';

        sprintf(perms_buff, "%c%c%c%c%c%c%c%c%c%c %c%c%c", ftype,
                        mode & S_IRUSR ? 'r' : '-',
                        mode & S_IWUSR ? 'w' : '-',
                        mode & S_IXUSR ? 'x' : '-',
                        mode & S_IRGRP ? 'r' : '-',
                        mode & S_IWGRP ? 'w' : '-',
                        mode & S_IXGRP ? 'x' : '-',
                        mode & S_IROTH ? 'r' : '-',
                        mode & S_IWOTH ? 'w' : '-',
                        mode & S_IXOTH ? 'x' : '-',
                        mode & S_ISUID ? 'U' : '-',
                        mode & S_ISGID ? 'G' : '-',
                        mode & S_ISVTX ? 'S' : '-');

        return (const char *)perms_buff;
}
char pathname[MAXPATHLEN];
void die(char *msg)
{
        perror(msg);
        exit(0);
}

        static int
one (const struct dirent *unused)
{
        return 1;
}
void command_ls1(char* args21)
{
	sum++;
        int count,i;
        struct direct **files;
        struct stat statbuf;
        char datestring[256];
        struct passwd pwent;
        struct passwd *pwentp;
        struct group grp;
        struct group *grpt;
        struct tm time;
        char buf[1024];
	char args9[256];
	if(args2[0]==0)
	  count=scandir("/home/dell",&files,one,alphasort);
	else
        count = scandir(args2, &files, one, alphasort);
        if(count > 0)
        {
                printf("total %d\n",count);
                for (i=0; i<count; ++i)
                {
                        if (stat(files[i]->d_name, &statbuf) == 0)
                        {
                                /* Print out type, permissions, and number of links. */
                                printf("%10.10s", get_perms(statbuf.st_mode));
                                printf(" %d", statbuf.st_nlink);

                                if (!getpwuid_r(statbuf.st_uid, &pwent, buf, sizeof(buf), &pwentp))
                                        printf(" %s", pwent.pw_name);
                                else
                                        printf(" %d", statbuf.st_uid);

                                if (!getgrgid_r (statbuf.st_gid, &grp, buf, sizeof(buf), &grpt))
                                        printf(" %s", grp.gr_name);
                                else
                                        printf(" %d", statbuf.st_gid);

                                /* Print size of file. */
                                printf(" %5d", (int)statbuf.st_size);

                                localtime_r(&statbuf.st_mtime, &time);
                                /* Get localized date string. */
                                strftime(datestring, sizeof(datestring), "%F %T", &time);

                                printf(" %s %s\n", datestring, files[i]->d_name);
                        }

                        free (files[i]);
                }
             free(files);
      }

}
