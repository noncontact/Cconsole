#include"singmanage.h"

int main()
{
	int Func;
	int EscapeWhile=TRUE;

	while(EscapeWhile){
		Func = Displaymenu();

		switch(Func){
		case INSERT:
			Insertmenu();
			break;
		case RETRIEVE:
			Retrievemenu();
			break;
		case PRINT:
			Printmenu();
			break;
		case REMOVE:
			Removemenu();
			break;
		case REWRITE:
			Rewriteprefermenu();
			break;
		case INIT:
			Initmenu();
			break;
		case ABOUT:
			Aboutmenu();
			break;
		case EXIT:
			EscapeWhile=FALSE;
			printf("\n\t 시스템을 종료합니다. 즐거운 하루 되십쇼!!\n\n");
			break;
		default:
			printf("잘못 입력 하셨습니다.    다시 입력해주십시오.\n\n");
		}//switch
		system("pause");
	}

	return 0;
}

int Displaymenu(){
	int nMenu;

	system("cls");

	printf("\n\n");
	printf("\t***************************************\n");
	printf("\t        노래 목록 관리 프로그램\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++\n");
	printf("\t            1. 입력\n");
	printf("\t            2. 검색\n");
	printf("\t            3. 출력\n");
	printf("\t            4. 제거\n");
	printf("\t            5. 선호도 수정\n");
	printf("\t            6. 목록 초기화\n");
	printf("\t            7. 제작자\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++\n");
	printf("\t            0. 종료\n");
	printf("\t***************************************\n");
	printf("\t   >>");
	scanf("%d",&nMenu);

	return nMenu;


	
}

void Insertmenu(){
	int Insertselect;

	system("cls");

	printf("\n\n");
	printf("\t***************************************\n");
	printf("\t               입력 매뉴\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++\n");
	printf("\t             1. 콘솔 입력\n");
	printf("\t             2. 파일 불러오기\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++\n");
	printf("\t             0. 돌아가기\n");
	printf("\t***************************************\n");
	printf("\t  >>");
	scanf("%d",&Insertselect);

	if(Insertselect ==0){
		printf("\t 초기화면으로 돌아갑니다.\n");
		return;
	}
	else if(Insertselect ==CONSOL_IN)
		Insertconsol();
	else if(Insertselect == FILE_IN)
		Insertfile();
	else printf("\t 제대로 입력해 주십시오. 초기화면으로 돌아갑니다.\n");
}
void Insertconsol(){

	SongList *pInput;
	SongList *pVisited, *pPrev;

	int position,i;
	int consol;

	system("cls");
	printf("\n\n");
	printf("\t***************************************\n");
	printf("\t      원하는 위치에 입력해 주세요!!\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++\n");
	printf("\t           1. 제일 앞\n");  
	printf("\t           2. 사용자 지정 위치\n");
	printf("\t           3. 제일 끝\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++\n");
	printf("\t             0. 돌아가기\n");
	printf("\t***************************************\n");
	printf("\t      >>");
	scanf("%d",&consol);

	if(consol==PREVIOUS)return;
	if(consol>=FIRST && consol<=LAST) {

		pInput= (SongList *)malloc(sizeof(SongList)); 
	    printf("\t  노래제목 >>");
		fflush(stdin);
		gets(pInput->chSongname);
	    //scanf("%s",(pInput->chSongname));
		printf("\t  가수 >>");
		fflush(stdin);
		gets(pInput->chSinger);
	    //scanf("%s",(pInput->chSinger));
		pVisited = pHeader;
		while(pVisited !=NULL){
			if((strcmp(pInput->chSongname,pVisited->chSongname)==0)&&(strcmp(pInput->chSinger,pVisited->chSinger)==0)){
				printf("\n\t  **이미 있는 노래입니다. 매인 매뉴로 돌아갑니다.**\n\n");
				free(pInput);
				return;
			}
			pVisited=pVisited->link;
		}
		printf("\t  장르 >>");
	    scanf("%s",(pInput->chJanre));
		while(TRUE){
		    printf("\t  선호도[1~5](소수점 첫째자리까지만 입력) >>");
	        scanf("%lf",&(pInput->lfPreference));
		    if(pInput->lfPreference>=1&&pInput->lfPreference<=5){
				break;
			}
		    printf("\t  [1~5] 사이 순자를 입력하세요.(입력 숫자 %.1lf)\n",pInput->lfPreference);
		}
	    pInput->link=NULL;

		switch(consol){

	        case FIRST:

		        pInput->link = pHeader;
		        pHeader = pInput;
				printf("\t    제일 앞으로 입력됫습니다.\n");
		        break;

	        case RANDOM:
		        if(pHeader==NULL){

			      pHeader =pInput;
			      printf("\n\t    목록이 비었습니다. 첫번째로 입력됬습니다. \n");
		        }else{
			        printf("\n\t        위치>>");
			        scanf("%d",&position);

			        if(position<=0){
				       printf("\n\t   입력 위치는%dth 입니다\n",position);    
				       printf("\t          인식 되지않는 위치입니다!!\n");
			        }else if(position==1){
				        pInput->link=pHeader;
				        pHeader= pInput;
				        printf("\n\t        제일 앞에 입력됬습니다.\n");
			        }
			        else{
				       pVisited = pHeader;
				       pPrev=NULL;
				       for(i=1;i<position;i++){
					       pPrev = pVisited;
					       pVisited=pVisited->link;
					       if (pVisited == NULL)break;
				       }
				       pInput->link = pPrev->link;
				       pPrev->link = pInput;

				       if(pVisited == NULL){
					      printf("\n\t          인식범위가 아닙니다 , 제일 끝에 입력됐습니다.\n");
				       }else{
					       printf("\n\t         %dth에 입력 됬습니다.\n",position);
				       }

			        }
		        }  

		        break;

	         case LAST:
		        if(pHeader==NULL){
			       pHeader = pInput;
		        }else{
		            pVisited =pHeader;

		            while(pVisited->link != NULL){

			            pVisited=pVisited->link;
		            }  
		            pInput->link=pVisited->link;
		            pVisited->link=pInput;
					printf("\n\t         마지막에 입력됬습니다!!\n");
		            break;
			        
	           }
	    }

	}
		

}
void Insertfile(){
	FILE *fpIn;
	int i,Node=0,Filelen=0,Count=0;
	char FileName[40];
	SongList *pInput,*pVisited; 

	system("cls");
	printf("\n\n");
	printf("\t***************************************\n");
	printf("\t       BINARY파일 불러오기!!\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++\n");
	printf("\n");
	printf("\t     BINARY파일 이름을 입력하세요 >>");
	scanf("%s",FileName);

	fpIn=fopen(FileName,"rb");
	if(fpIn == NULL){
		printf("\t    (%s)파일을 불러올수 없습니다.\n",FileName);
		return;
	}

	fseek(fpIn,0,SEEK_END);
	Filelen=ftell(fpIn);
	rewind(fpIn);
	Node = Filelen / sizeof(SongList);
	
	for(i=0;i<Node;i++){
		pInput =(SongList *)malloc(sizeof(SongList));
		fread(pInput,sizeof(SongList),1,fpIn);
		pVisited = pHeader;
		while(pVisited !=NULL){
			if((strcmp(pInput->chSongname,pVisited->chSongname)==0)&&(strcmp(pInput->chSinger,pVisited->chSinger)==0)){
				Count++;
				free(pInput);
				return;
			}
			pVisited=pVisited->link;
		}
		pInput->link=NULL;

		if(pHeader==NULL){
			       pHeader = pInput;
		}
		else{
		     pVisited =pHeader;

		     while(pVisited->link != NULL){

			      pVisited=pVisited->link;
		     }  
		     pInput->link=pVisited->link;
		     pVisited->link=pInput; 	
		}
	}
	if(Count==0){
	  printf("\t      (%s)파일을 성공적으로 불려왔습니다!!\n",FileName);
	}
	else{
		printf("\t      %d의 목록이 중복되었 습니다.\n\t  그외 (%s)파일을 성공적으로 불려왔습니다!!\n",FileName);
	}
	fclose(fpIn);
}

void Retrievemenu(){
	int Retrieveselect;

	
	system("cls");
	printf("\n\n");
	if(pHeader == NULL){
		printf("\t         목록이 비어 있습니다!!\n\n");
		return;
	}

	
	printf("\t***************************************\n");
	printf("\t               검색 매뉴\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++\n");
	printf("\t             1. 노래 검색\n");
	printf("\t             2. 선호도 검색\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++\n");
	printf("\t             0. 돌아가기\n");
	printf("\t***************************************\n");
	printf("\t  >>");
	scanf("%d",&Retrieveselect);

	if(Retrieveselect ==0){
		printf("\t 초기화면으로 돌아갑니다.\n");
		return;
	}
	else if(Retrieveselect ==SONG)
		Retrievesongname();
	else if(Retrieveselect == PREFER)
		Retrieveprefer();
	else printf("\t 제대로 입력해 주십시오. 초기화면으로 돌아갑니다.\n");
}
void Retrievesongname(){
	SongList *pVisited;
	char Songname[30];
	int nCount=0;

	pVisited=pHeader;
	system("cls");
	printf("\n\n");
	printf("\t   찾기 원하는 노래 제목을 입력해주세요>>");
	fflush(stdin);
	gets(Songname);
	printf("\t***************************************\n");
	printf("\t  제목     가수     장르     선호도\n");
	printf("\t***************************************\n");
	while(pVisited!=NULL){
		if(strcmp(Songname,pVisited->chSongname)==0){
			printf("\t%10s   %5s   %5s    %3.1lf\n",pVisited->chSongname,pVisited->chSinger,pVisited->chJanre,pVisited->lfPreference);
			printf("\t+++++++++++++++++++++++++++++++++++++++\n");
			nCount++;
		}
		pVisited=pVisited->link;
	}
	if(nCount == FALSE)printf("\n\t 찾으시는 노래가 존재하지 않습니다.\n");
	else printf("\n\t 검색 결과가 총 %d건 조회 됐습니다.\n",nCount);

}
void Retrieveprefer(){
	SongList *pVisited;
	int nPrefer;
	int nCount=0;

	pVisited=pHeader;
	system("cls");
	printf("\n\n");
	printf("\t   찾기 원하는 선호도를 입력해주세요>>");
	scanf("%d",&nPrefer);
	printf("\t***************************************\n");
	printf("\t  제목     가수     장르     선호도\n");
	printf("\t***************************************\n");
	while(pVisited!=NULL){
		if(nPrefer<=(pVisited->lfPreference)&&((nPrefer+1)>(pVisited->lfPreference))){
			printf("\t%10s   %5s   %5s    %3.1lf\n",pVisited->chSongname,pVisited->chSinger,pVisited->chJanre,pVisited->lfPreference);
			printf("\t+++++++++++++++++++++++++++++++++++++++\n");
			nCount++;
		}
		pVisited=pVisited->link;
	}
	if(nCount == FALSE)printf("\n\t 찾으시는 노래가 존재하지 않습니다.\n");
	else printf("\n\t 검색 결과가 총 %d건 조회 됐습니다.\n",nCount);

}

void Printmenu(){
	int Printselect;

	system("cls");

	printf("\n\n");
	if(pHeader == NULL){
		printf("\t         목록이 비어 있습니다!!\n\n");
		return;
	}
	printf("\t***************************************\n");
	printf("\t               출력 매뉴\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++\n");
	printf("\t             1. 콘솔 출력\n");
	printf("\t             2. 파일 저장하기\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++\n");
	printf("\t             0. 돌아가기\n");
	printf("\t***************************************\n");
	printf("\t  >>");
	scanf("%d",&Printselect);

	if(Printselect ==0){
		printf("\t 초기화면으로 돌아갑니다.\n");
		return;
	}
	else if(Printselect ==CONSOL_IN)
		Printconsol();
	else if(Printselect == FILE_IN)
		Printfile();
	else printf("\t 제대로 입력해 주십시오. 초기화면으로 돌아갑니다.\n");
}
void Printconsol(){
	int nMenu;

	system("cls");
	printf("\n\n");
	printf("\t***************************************\n");
	printf("\t            콘솔 출력 매뉴\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++\n");
	printf("\t             1. 입력순 출력\n");
	printf("\t             2. 선호도순 출력\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++\n");
	printf("\t            0. 돌아가기\n");
	printf("\t***************************************\n");
	printf("\t    >>");
	scanf("%d",&nMenu);

	if(nMenu==PREVIOUS) return;

	else if(nMenu ==UNORDERED)
		PCunordered();
	else if(nMenu == PREFER)
		PCprefer();
	else printf("\t 제대로 입력해 주십시오. 초기화면으로 돌아갑니다.\n");
}
void PCunordered(){
	SongList *pVisited;

	system("cls");//꾸미기
	printf("\n\n");//꾸미기
	printf("\t***************************************\n");
	printf("\t             입력순 출력\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++\n");
	printf("\t  제목     가수     장르     선호도\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++\n");
	pVisited = pHeader;
	while(pVisited!=NULL){
		printf("\t%10s   %5s   %5s    %3.1lf\n",pVisited->chSongname,pVisited->chSinger,pVisited->chJanre,pVisited->lfPreference);
		printf("\t+++++++++++++++++++++++++++++++++++++++\n");
		pVisited=pVisited->link;
	}
}
void PCprefer(){
	double a=50;
	SongList *pVisited;

	system("cls");
	printf("\n\n");
	printf("\t***************************************\n");
	printf("\t             입력순 출력\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++\n");
	printf("\t  제목     가수     장르     선호도\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++\n");
	while(a>0){
		
		pVisited = pHeader;
		while(pVisited!=NULL){
			if(((pVisited->lfPreference))==(a/10.0)){
				printf("\t%10s   %5s   %5s    %3.1lf\n",pVisited->chSongname,pVisited->chSinger,pVisited->chJanre,pVisited->lfPreference);
		        printf("\t+++++++++++++++++++++++++++++++++++++++\n");
			}
			pVisited=pVisited->link;
		}
		
		a=a-1;
	}
}
void Printfile(){
	int nMenu;

	system("cls");
	printf("\n\n");
	printf("\t***************************************\n");
	printf("\t             파일 저장매뉴\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++\n");
	printf("\t             1. 입력순 저장\n");
	printf("\t             2. 선호도순 저장\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++\n");
	printf("\t            0. 돌아가기\n");
	printf("\t***************************************\n");
	printf("\t    >>");
	scanf("%d",&nMenu);

	if(nMenu==PREVIOUS) return;

	else if(nMenu ==UNORDERED)
		PFunordered();
	else if(nMenu == PREFER)
		PFprefer();
	else printf("\t 제대로 입력해 주십시오. 초기화면으로 돌아갑니다.\n");

}
void PFunordered(){
	FILE *fpOut;
	char FileName[40];
	SongList *pVisited;

	system("cls");
	printf("\n\n");
	printf("\t***************************************\n");
	printf("\t             입력순 출력\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++\n");
	printf("\n");
	printf("\t BINARY파일 이름을 입력하세요>>"); 
	scanf("%s",FileName);
	fpOut=fopen(FileName,"wb");
	if(fpOut ==NULL){
		printf("\t    (%s)파일을 불러올수 없습니다.\n",FileName);
		return;
	}
	pVisited=pHeader;
	while(pVisited != NULL){
		fwrite(pVisited,sizeof(SongList),1,fpOut);
		pVisited = pVisited->link;
	}
	printf("\t (%s)파일을 성공적으로 저장 했습니다!!\n",FileName);
	fclose(fpOut);
}
void PFprefer(){
	FILE *fpOut;
	int i;
	char FileName[40];
	SongList *pVisited;

	system("cls");
	printf("\n\n");
	printf("\t***************************************\n");
	printf("\t             선호도순 출력\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++\n");
	printf("\n");
	printf("\t BINARY파일 이름을 입력하세요>>"); 
	scanf("%s",FileName);
	fpOut=fopen(FileName,"wb");
	if(fpOut ==NULL){
		printf("\t    (%s)파일을 불러올수 없습니다.\n",FileName);
		return;
	}
	for(i=5;i>0;i--){
	    pVisited=pHeader;
	    while(pVisited != NULL){
			if(pVisited->lfPreference==i){
		        fwrite(pVisited,sizeof(SongList),1,fpOut);
			}
		    pVisited = pVisited->link;
	    }
	}
	printf("\t (%s)파일을 성공적으로 저장 했습니다!!\n",FileName);
	fclose(fpOut);
}
void Removemenu(){
	printf("4\n");
}

void Rewriteprefermenu(){
	printf("5\n");
}

void Initmenu(){
	printf("6\n");
}

void Aboutmenu(){
	printf("7\n");
}
