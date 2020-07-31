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
char* good33;
char **args35;
char *command[256];
char *command1[256];
char **split_line(char *line,char *seperator);
void pipehandler(char *line);
void command_cd(char s[]);
void command_ls(char* hoho);
char hostname[1024];
char q[100],r[100];
int l=-1,j,donkey=1,background,stud=-1;
char s='/';
char p='/';
int num=0,status;
int position=0;
struct stat sts;
char **args;
char **args33;
FILE* fp=NULL;
FILE* f;
char status99;
int status11;
int duty,zet;
int sum=0,many=0,sort=0;
int bg;
char args2[100];
int PID;
int count,teju,filed,filed1;
char** redirect(char **dos);
typedef struct backgrpr
{
	char process[1024];
	pid_t pid99,pgid;
	//struct bp *next;
}bp;
bp array[1024];
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
	char line1[1000];
	int i,length2,w,init=0,length=0,length1,k,count=0;
	long long int x;
	DIR *myDirectory;
	FILE* p;
	int dodo;
	int dodo1,status,st;
	pid_t pid;
	pid_t pid99;
	char **args1;char **args3;
	display();
	while(2==2)
	{

		count=0;
		teju=0;
		dodo=0;
		dodo1=0;
		background=0;
		line=read_line();
		for(zet=0;zet<strlen(line);zet++)
		{
			if(line[zet]=='|'||line[zet]=='>'||line[zet]=='<')
				dodo++;
			if(line[zet]=='&')
				background=1;
			else
				background=0;
		}
			if(dodo>0)
				pipehandler(line);
			else{
				args=split_line(line," \t");if(background==1)args[position-1]=NULL;}
		if(strcmp(args[0],"quit")==0)
			exit(0);
		pid99=fork();
		if(pid99==0)
		{		
			if(!strcmp(args[0],"pinfo"))
			{
				many++;
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
				//printf("%s@%s:~/%s$",getenv("USER"),hostname,args2);
			}
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
			//printf("\n%s@%s:~/%s$",getenv("USER"),hostname,args2);
		}
		if(!strcmp(args[0],"ls"))
		{ 
			many++;
			if(args2[0]==0){

				command_ls("/home/dell");}
			else{     
				command_ls(args2);}
			//printf("\n%s@%s:~/%s$",getenv("USER"),hostname,args2);
		}
		if(!strcmp(args[0],"echo"))
		{
			many++;
			printf("\n");
			for(int z=1;z<position;z++)
				printf("%s ",args[z]);
			//		printf("\n%s@%s:~/%s$",getenv("USER"),hostname,args2);
		}
		if(strcmp(args[0],"setenv")==0)
		{many++;
			if((position-1)==0)
				perror("ERROR: insufficient number of command line arguments\n");
			if((position-1)>=3)
				perror("ERROR: Too many arguments\n");
			setenv(args[1],args[2],1);
		}
		if(strcmp(args[0],"unsetenv")==0)
		{many++;
			if((position-1)==0)
				perror("ERROR: Less no of arguments\n");
			if((position-1)>=2)
				perror("ERROR: Too many arguments\n");
			unsetenv(args[1]);
		}
		/*if(strcmp(args[0],"jobs")==0)
		{
			int some;
			for(some=0;some<=stud;some++)
			{
				if(array[some].pgid==0)
					status99='R';
				else if(array[some].pgid==1)
					status99='S';
				printf("[%d] %c %s[%d]",some+1,status99,array[some].process,array[some].pid99);
				printf("\n");
			}
		}*/
		if(strcmp(args[0],"overkill")==0)
		{
			for(int studi=0;studi<=stud;studi++)
			{
				kill(array[studi].pid99,9);
			}
		}
		if(background==0)
			printf("\n%s@%s:~/%s$",getenv("USER"),hostname,args2);
		if(many==0&&(strcmp(args[0],"quit")!=0))
		{
			execvp(args[0],args);
			printf("\n%s@%s:~/%s$",getenv("USER"),hostname,args2);
		}
		else
			break;
		free(line);
		free(args);
		free(args33);
		many=0;
	}
	else if(pid99>0&&background==0)
	{
		wait(NULL);
	}
	else if(pid99>0 && background==1)
	{
		stud++;
		/*status=waitpid(pid99,&st,WNOHANG);
		if(status>0)
		{
			if(WIFEXITED(st)==1)
				printf("\nprocess with pid %d exited normally\n",status);
			else if(WIFSIGNALED(st)==1)
				printf("\nProcess with pid %d did not exit normally\n",status);
			
		}*/
		strcpy(array[sort].process,args[0]);
		array[sort].pid99=pid99;
		sort++;//int sis;
		/*for(sis=0;sis<=stud;sis++)
		{
			status11=waitpid(array[sis].pid99,&st,WNOHANG|WUNTRACED);
			if(status11==0)
				perror("ERROR\n");
			if(status11>0)
			{
				if(WIFSTOPPED(st)!=0)
					array[sis].pgid=1;
				else if(WIFCONTINUED(st)!=0)
				      array[sis].pgid=0;
			}	
		}*/
	}
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
		if(strcmp(seperator,"|")==0)
			teju++;
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
void pipehandler(char *line)
{
	args=split_line(line,"|");
	int filedes[2];
	int filedes2[2];
	pipe(filedes);
	pipe(filedes2);
	int k=0;
	while(args[k]!=NULL)
	{
		args33=split_line(args[k]," ");
		int pid=fork();
		if(pid==0)
		{
			if((k%2)!=0)
			{
				if(k!=(teju-1))
					dup2(filedes2[1],STDOUT_FILENO);
				if(k!=0)
					dup2(filedes[0],STDIN_FILENO);
			}
			else
			{
				if(k!=(teju-1))
					dup2(filedes[1],STDOUT_FILENO);
				if(k!=0)
					dup2(filedes2[0],STDIN_FILENO);
			}
			args33=redirect(args33);
			execvp(args33[0],args33);
		}
		else
		{
			if((k%2!=0))
			{
				if(k!=(teju-1))
					close(filedes[0]);
				if(k!=0)
					close(filedes2[1]);
			}
			else
			{
				if(k!=(teju-1))
					close(filedes[1]);
				if(k!=0)
					close(filedes2[0]);
			}
			wait(NULL);
		}
		k++;
	}
	return;
}
char** redirect(char **dos)
{
	int i,juju=0;
	while(args33[juju]!=NULL)
	{
		if(args33[juju][0]=='>')
		{
			if(args33[juju][1]=='>')
			{
				args33[juju]=NULL;
				filed=open(args33[juju+1],O_WRONLY|O_CREAT|O_APPEND,0644);
				if(filed<0)
					perror("error1");
				dup2(filed,STDOUT_FILENO);
				close(filed);
			}
			else if(args33[juju][1]==0)
			{
				args33[juju]=NULL;
				filed=open(args33[juju+1],O_WRONLY|O_CREAT|O_TRUNC,0644);
				if(filed<0)
					perror("error2");
				dup2(filed,STDOUT_FILENO);
				close(filed);
			}
		}
		else if(args33[juju][0]=='<')
		{
			args33[juju]=NULL;
			filed1=open(args33[juju+1],O_RDONLY);
			if(filed1<0)
				perror("error3");
			dup2(filed1,STDIN_FILENO);
			close(filed1);
		}
		juju++;
	}
	return args33;
}
