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
			printf("\n\t �ý����� �����մϴ�. ��ſ� �Ϸ� �ǽʼ�!!\n\n");
			break;
		default:
			printf("�߸� �Է� �ϼ̽��ϴ�.    �ٽ� �Է����ֽʽÿ�.\n\n");
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
	printf("\t        �뷡 ��� ���� ���α׷�\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++\n");
	printf("\t            1. �Է�\n");
	printf("\t            2. �˻�\n");
	printf("\t            3. ���\n");
	printf("\t            4. ����\n");
	printf("\t            5. ��ȣ�� ����\n");
	printf("\t            6. ��� �ʱ�ȭ\n");
	printf("\t            7. ������\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++\n");
	printf("\t            0. ����\n");
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
	printf("\t               �Է� �Ŵ�\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++\n");
	printf("\t             1. �ܼ� �Է�\n");
	printf("\t             2. ���� �ҷ�����\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++\n");
	printf("\t             0. ���ư���\n");
	printf("\t***************************************\n");
	printf("\t  >>");
	scanf("%d",&Insertselect);

	if(Insertselect ==0){
		printf("\t �ʱ�ȭ������ ���ư��ϴ�.\n");
		return;
	}
	else if(Insertselect ==CONSOL_IN)
		Insertconsol();
	else if(Insertselect == FILE_IN)
		Insertfile();
	else printf("\t ����� �Է��� �ֽʽÿ�. �ʱ�ȭ������ ���ư��ϴ�.\n");
}
void Insertconsol(){

	SongList *pInput;
	SongList *pVisited, *pPrev;

	int position,i;
	int consol;

	system("cls");
	printf("\n\n");
	printf("\t***************************************\n");
	printf("\t      ���ϴ� ��ġ�� �Է��� �ּ���!!\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++\n");
	printf("\t           1. ���� ��\n");  
	printf("\t           2. ����� ���� ��ġ\n");
	printf("\t           3. ���� ��\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++\n");
	printf("\t             0. ���ư���\n");
	printf("\t***************************************\n");
	printf("\t      >>");
	scanf("%d",&consol);

	if(consol==PREVIOUS)return;
	if(consol>=FIRST && consol<=LAST) {

		pInput= (SongList *)malloc(sizeof(SongList)); 
	    printf("\t  �뷡���� >>");
		fflush(stdin);
		gets(pInput->chSongname);
	    //scanf("%s",(pInput->chSongname));
		printf("\t  ���� >>");
		fflush(stdin);
		gets(pInput->chSinger);
	    //scanf("%s",(pInput->chSinger));
		pVisited = pHeader;
		while(pVisited !=NULL){
			if((strcmp(pInput->chSongname,pVisited->chSongname)==0)&&(strcmp(pInput->chSinger,pVisited->chSinger)==0)){
				printf("\n\t  **�̹� �ִ� �뷡�Դϴ�. ���� �Ŵ��� ���ư��ϴ�.**\n\n");
				free(pInput);
				return;
			}
			pVisited=pVisited->link;
		}
		printf("\t  �帣 >>");
	    scanf("%s",(pInput->chJanre));
		while(TRUE){
		    printf("\t  ��ȣ��[1~5](�Ҽ��� ù°�ڸ������� �Է�) >>");
	        scanf("%lf",&(pInput->lfPreference));
		    if(pInput->lfPreference>=1&&pInput->lfPreference<=5){
				break;
			}
		    printf("\t  [1~5] ���� ���ڸ� �Է��ϼ���.(�Է� ���� %.1lf)\n",pInput->lfPreference);
		}
	    pInput->link=NULL;

		switch(consol){

	        case FIRST:

		        pInput->link = pHeader;
		        pHeader = pInput;
				printf("\t    ���� ������ �Էµ̽��ϴ�.\n");
		        break;

	        case RANDOM:
		        if(pHeader==NULL){

			      pHeader =pInput;
			      printf("\n\t    ����� ������ϴ�. ù��°�� �Է���ϴ�. \n");
		        }else{
			        printf("\n\t        ��ġ>>");
			        scanf("%d",&position);

			        if(position<=0){
				       printf("\n\t   �Է� ��ġ��%dth �Դϴ�\n",position);    
				       printf("\t          �ν� �����ʴ� ��ġ�Դϴ�!!\n");
			        }else if(position==1){
				        pInput->link=pHeader;
				        pHeader= pInput;
				        printf("\n\t        ���� �տ� �Է���ϴ�.\n");
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
					      printf("\n\t          �νĹ����� �ƴմϴ� , ���� ���� �Էµƽ��ϴ�.\n");
				       }else{
					       printf("\n\t         %dth�� �Է� ����ϴ�.\n",position);
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
					printf("\n\t         �������� �Է���ϴ�!!\n");
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
	printf("\t       BINARY���� �ҷ�����!!\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++\n");
	printf("\n");
	printf("\t     BINARY���� �̸��� �Է��ϼ��� >>");
	scanf("%s",FileName);

	fpIn=fopen(FileName,"rb");
	if(fpIn == NULL){
		printf("\t    (%s)������ �ҷ��ü� �����ϴ�.\n",FileName);
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
	  printf("\t      (%s)������ ���������� �ҷ��Խ��ϴ�!!\n",FileName);
	}
	else{
		printf("\t      %d�� ����� �ߺ��Ǿ� ���ϴ�.\n\t  �׿� (%s)������ ���������� �ҷ��Խ��ϴ�!!\n",FileName);
	}
	fclose(fpIn);
}

void Retrievemenu(){
	int Retrieveselect;

	
	system("cls");
	printf("\n\n");
	if(pHeader == NULL){
		printf("\t         ����� ��� �ֽ��ϴ�!!\n\n");
		return;
	}

	
	printf("\t***************************************\n");
	printf("\t               �˻� �Ŵ�\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++\n");
	printf("\t             1. �뷡 �˻�\n");
	printf("\t             2. ��ȣ�� �˻�\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++\n");
	printf("\t             0. ���ư���\n");
	printf("\t***************************************\n");
	printf("\t  >>");
	scanf("%d",&Retrieveselect);

	if(Retrieveselect ==0){
		printf("\t �ʱ�ȭ������ ���ư��ϴ�.\n");
		return;
	}
	else if(Retrieveselect ==SONG)
		Retrievesongname();
	else if(Retrieveselect == PREFER)
		Retrieveprefer();
	else printf("\t ����� �Է��� �ֽʽÿ�. �ʱ�ȭ������ ���ư��ϴ�.\n");
}
void Retrievesongname(){
	SongList *pVisited;
	char Songname[30];
	int nCount=0;

	pVisited=pHeader;
	system("cls");
	printf("\n\n");
	printf("\t   ã�� ���ϴ� �뷡 ������ �Է����ּ���>>");
	fflush(stdin);
	gets(Songname);
	printf("\t***************************************\n");
	printf("\t  ����     ����     �帣     ��ȣ��\n");
	printf("\t***************************************\n");
	while(pVisited!=NULL){
		if(strcmp(Songname,pVisited->chSongname)==0){
			printf("\t%10s   %5s   %5s    %3.1lf\n",pVisited->chSongname,pVisited->chSinger,pVisited->chJanre,pVisited->lfPreference);
			printf("\t+++++++++++++++++++++++++++++++++++++++\n");
			nCount++;
		}
		pVisited=pVisited->link;
	}
	if(nCount == FALSE)printf("\n\t ã���ô� �뷡�� �������� �ʽ��ϴ�.\n");
	else printf("\n\t �˻� ����� �� %d�� ��ȸ �ƽ��ϴ�.\n",nCount);

}
void Retrieveprefer(){
	SongList *pVisited;
	int nPrefer;
	int nCount=0;

	pVisited=pHeader;
	system("cls");
	printf("\n\n");
	printf("\t   ã�� ���ϴ� ��ȣ���� �Է����ּ���>>");
	scanf("%d",&nPrefer);
	printf("\t***************************************\n");
	printf("\t  ����     ����     �帣     ��ȣ��\n");
	printf("\t***************************************\n");
	while(pVisited!=NULL){
		if(nPrefer<=(pVisited->lfPreference)&&((nPrefer+1)>(pVisited->lfPreference))){
			printf("\t%10s   %5s   %5s    %3.1lf\n",pVisited->chSongname,pVisited->chSinger,pVisited->chJanre,pVisited->lfPreference);
			printf("\t+++++++++++++++++++++++++++++++++++++++\n");
			nCount++;
		}
		pVisited=pVisited->link;
	}
	if(nCount == FALSE)printf("\n\t ã���ô� �뷡�� �������� �ʽ��ϴ�.\n");
	else printf("\n\t �˻� ����� �� %d�� ��ȸ �ƽ��ϴ�.\n",nCount);

}

void Printmenu(){
	int Printselect;

	system("cls");

	printf("\n\n");
	if(pHeader == NULL){
		printf("\t         ����� ��� �ֽ��ϴ�!!\n\n");
		return;
	}
	printf("\t***************************************\n");
	printf("\t               ��� �Ŵ�\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++\n");
	printf("\t             1. �ܼ� ���\n");
	printf("\t             2. ���� �����ϱ�\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++\n");
	printf("\t             0. ���ư���\n");
	printf("\t***************************************\n");
	printf("\t  >>");
	scanf("%d",&Printselect);

	if(Printselect ==0){
		printf("\t �ʱ�ȭ������ ���ư��ϴ�.\n");
		return;
	}
	else if(Printselect ==CONSOL_IN)
		Printconsol();
	else if(Printselect == FILE_IN)
		Printfile();
	else printf("\t ����� �Է��� �ֽʽÿ�. �ʱ�ȭ������ ���ư��ϴ�.\n");
}
void Printconsol(){
	int nMenu;

	system("cls");
	printf("\n\n");
	printf("\t***************************************\n");
	printf("\t            �ܼ� ��� �Ŵ�\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++\n");
	printf("\t             1. �Է¼� ���\n");
	printf("\t             2. ��ȣ���� ���\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++\n");
	printf("\t            0. ���ư���\n");
	printf("\t***************************************\n");
	printf("\t    >>");
	scanf("%d",&nMenu);

	if(nMenu==PREVIOUS) return;

	else if(nMenu ==UNORDERED)
		PCunordered();
	else if(nMenu == PREFER)
		PCprefer();
	else printf("\t ����� �Է��� �ֽʽÿ�. �ʱ�ȭ������ ���ư��ϴ�.\n");
}
void PCunordered(){
	SongList *pVisited;

	system("cls");//�ٹ̱�
	printf("\n\n");//�ٹ̱�
	printf("\t***************************************\n");
	printf("\t             �Է¼� ���\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++\n");
	printf("\t  ����     ����     �帣     ��ȣ��\n");
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
	printf("\t             �Է¼� ���\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++\n");
	printf("\t  ����     ����     �帣     ��ȣ��\n");
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
	printf("\t             ���� ����Ŵ�\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++\n");
	printf("\t             1. �Է¼� ����\n");
	printf("\t             2. ��ȣ���� ����\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++\n");
	printf("\t            0. ���ư���\n");
	printf("\t***************************************\n");
	printf("\t    >>");
	scanf("%d",&nMenu);

	if(nMenu==PREVIOUS) return;

	else if(nMenu ==UNORDERED)
		PFunordered();
	else if(nMenu == PREFER)
		PFprefer();
	else printf("\t ����� �Է��� �ֽʽÿ�. �ʱ�ȭ������ ���ư��ϴ�.\n");

}
void PFunordered(){
	FILE *fpOut;
	char FileName[40];
	SongList *pVisited;

	system("cls");
	printf("\n\n");
	printf("\t***************************************\n");
	printf("\t             �Է¼� ���\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++\n");
	printf("\n");
	printf("\t BINARY���� �̸��� �Է��ϼ���>>"); 
	scanf("%s",FileName);
	fpOut=fopen(FileName,"wb");
	if(fpOut ==NULL){
		printf("\t    (%s)������ �ҷ��ü� �����ϴ�.\n",FileName);
		return;
	}
	pVisited=pHeader;
	while(pVisited != NULL){
		fwrite(pVisited,sizeof(SongList),1,fpOut);
		pVisited = pVisited->link;
	}
	printf("\t (%s)������ ���������� ���� �߽��ϴ�!!\n",FileName);
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
	printf("\t             ��ȣ���� ���\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++\n");
	printf("\n");
	printf("\t BINARY���� �̸��� �Է��ϼ���>>"); 
	scanf("%s",FileName);
	fpOut=fopen(FileName,"wb");
	if(fpOut ==NULL){
		printf("\t    (%s)������ �ҷ��ü� �����ϴ�.\n",FileName);
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
	printf("\t (%s)������ ���������� ���� �߽��ϴ�!!\n",FileName);
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
