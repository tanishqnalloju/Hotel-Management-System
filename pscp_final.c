//HEADER FILES INCLUSION
#include<stdio.h>		//FOR STANDARD INPUT AND OUTPUT	
//#include<conio.h>		//FOR RUNNING IN TURBO C COMPILER
#include<string.h>		//FOR STRING FUNCTIONS
#include<math.h>		//FOR MATH FUNCTIONS
#include<stdlib.h>		//STANDARD LIBRARY

	//GLOBAL VARIABLES 
	int trash; //FOR TRASH
	
	//FUNCTION PROTOYPES 
	void ravail(void);				//FOR DISPLAYING AVAILABILITY OF ROOMS 
	void rfeatures(void);			//FOR FEATURES OF ROOMS
	void ralloc(void);				//ROOM ALLOCATION
	//void custde(void);				//TO DISPLAY THE CUTOMER DETAILS
	void rdealloc(void);			//TO VACATE A ROOM
	//void rest(struct cust ptr2);	//TO SELECT THE MENU FROM THE RESTAURANT AND TAKE ORDER
	//float billing();				//TO PERFORM THE TOTAL BILLING AND DISPLAY
	
	void scr_header(void);	//FOR HEADER DISPLAY
	void scr_menu(void);	//FOR MENU DISPLAY
	void scr_welcome(void);	//FOR WELCOME DISPLAY
	void intialize(void);	//FOR INTIALIZING THE ROOMS WITH NULL OR '0' AS DEFAULT
	
	struct bill{
			
		float total_bill;
	  float restaraunt_bill;
		float room_bill;
		};
	
	struct rest{
			//members
		float serv_charge;
	  float tot_price;
	  float food_bill;
		};


	struct hot{
	
			
		struct rooms{
			
			char rcat;
			float rprice;
			int avail:1;//BIT FIELD
			
			int persons,add_per;
			
			int dyalloc;
			
			float room_bill;
				struct custde{
				
					char name[30];//FOR NAME
					char address[50];//FOR ADDRESS
					char ph[20];//FOR PHONE NUMBER
					int cust_id;
					
					struct rest res;
					struct bill billo;
					
				}cust,*cust_ptr,*cust_prt2;//FOR CUSTOMER DETAILS
			
			}room[10],*room_ptr;//FOR ROOM DETAILS
		
		
				
	}hot,*hot_ptr;//MAIN STRUCTURE FOR HOTEL
	
	
	char rcattype(){
		char cat;
		int rand1;		
		rand1=rand()%5;
		if(rand1==0)
		  cat='S';
		else if(rand1==1)
		  cat='D';
		else if(rand1==2)
		  cat='G';
		else if(rand1==3)
		  cat='C';
		else if(rand1==4)
		  cat='E';
		
		return cat;			
	}//FOR RETURNING A RANDOM ROOM CATEGORY
	
	
	void intialize(void){
		for(int i=0;i<10;i++){
			hot.room[i].avail=0;
			hot.room[i].rcat=rcattype();
		}
	}
	
	
	void ravail(void){
		printf("\n Room no   \t\t Availability \t\t Room type");
		for(int i=0;i<10;i++){
			 if(hot.room[i].avail==0){
				 printf("\n %d \t\t\t\t%d\t\t\t%c",i+1,hot.room[i].avail,hot.room[i].rcat);
			 }
		}
		printf("\nLegend");
		printf("\n1.Sp.delux-\t'S'\n2.Delux-\t'D'\n3.General-\t'G'\n4.Couple-\t'C'\n5.Couple Deluxe-'E'");				
	}
	
	
	void ralloc(void){
	  int all_rno=0;
	  ravail();
	  printf("\n Enter the room number from above :");
	  scanf("%d",&all_rno);
	  
			if(hot.room[all_rno-1].avail==1){
				printf("\nThe room is already booked!!!\n Select an another option");
				ralloc();
			}
	  hot.room[all_rno-1].avail=1;
	  printf("\n Enter the customer details below ");
	  printf("\nEnter name");
	  scanf("%s",hot.room[all_rno].cust.name);
	  printf("\nAddress");
	  scanf("%s",hot.room[all_rno].cust.address);
	  printf("\n Phone number");
	  scanf("%s",hot.room[all_rno].cust.ph);
	  hot.room[all_rno].cust.cust_id=rand()%1000+all_rno;
	  printf("\n Your customer id is %d",hot.room[all_rno].cust.cust_id);
	  
	}
	
	
	void custde(void){
	  int custid;
	  printf("\n Enter the customer id");
	  scanf("%d",&custid);
	  
	  for(int j=0;j<10;j++){
	    if(hot.room[j].cust.cust_id==custid){
	      printf("\nCustomer details are :");
	      printf("\n Customer id: %d",hot.room[j].cust.cust_id);
	      printf("\n Name: %s",hot.room[j].cust.name);
	      printf("\n Address: %s",hot.room[j].cust.address);
	      printf("\n Phone Number %s",hot.room[j].cust.ph);
			break;	      
	    }
		
	  }
	}
	
	
	void rdealloc(void){
	  int de_rno,de_custid;
	  printf("\n Enter the room no and customer id to de-allocate the room");
	  scanf("%d %d",&de_rno,&de_custid);
	  if(hot.room[de_rno].cust.cust_id==de_custid){
			printf("Record identified");
			printf("Room Deallocated");
			hot.room[de_rno].cust.cust_id=0;
			hot.room[de_rno].avail=0;
		}
	  else {
			printf("\nRecord not found , enter a valid record numbers");
			rdealloc();
		}
	}
	
	void rest(void) {
		int items=0;  
		int ch_rno=0,ch_custid=0;
		float price[11]={245,245,245,245,240,240,240,240,235,235,0};
		char food[11][40]={"Idli","Vada","Dosa","Onion Dosa","Masala Dosa","Chapathi","Parantha","Puri","Chole Batura","Fried Rice","Exit"};
		
		printf("\n Enter the room no and customer id for Restaurant");
				scanf("%d %d",&ch_rno,&ch_custid);
				
				if(hot.room[ch_rno].cust.cust_id==ch_custid ){
				  
		printf("\nMenu");
		printf("\nItem are served on the basis of availability. Tax not included");
			for(int d=0;d<11;d++){
				printf("\n%d\t%s\t%4.2f",d+1,food[d],price[d]);
			}
	
		int rest_choice=0;
		float charges=0;
			  
			 do{
			printf("\nEnter a choice ");
			scanf("%d",&rest_choice);
		
			 charges +=price[rest_choice-1];
			printf("cahrge %4.4f",charges);
			if(rest_choice!=11)
			  items++;
		  }while(rest_choice!=11);
		  
		  if(items==0){
		    printf("no items have been selected");
		    scr_menu();
		  }
		  
		  hot.room[ch_rno].cust.res.food_bill=charges;
		  printf("%4.4f",hot.room[ch_rno].cust.res.food_bill);
		  hot.room[ch_rno].cust.res.serv_charge=(charges*2.5/100);
		  hot.room[ch_rno].cust.res.tot_price=(hot.room[ch_rno].cust.res.food_bill+hot.room[ch_rno].cust.res.serv_charge);
	    printf("\n Items ordered : %d",items);
	    printf("\n Food Bill: %4.4f",hot.room[ch_rno].cust.res.food_bill);
	    printf("\n Service Bill: %4.4f",hot.room[ch_rno].cust.res.serv_charge);
	    printf("\n Total Bill: %4.4f",hot.room[ch_rno].cust.res.tot_price);
	    scr_menu();
	
			    	
				}
				
			    else{
					printf("\nEnter a valid room no and customer id");
					rest();
				}
			
	}
	
	float billing(void){
	  int de_rno,de_custid;
	  int bill_addper=0;
	  printf("\n Enter the room no and customer id to de-allocate the room");
	  scanf("%d %d",&de_rno,&de_custid);
	  if(hot.room[de_rno].cust.cust_id==de_custid){
		
	
		printf("\nEnter the number of days stayed");
		scanf("%d",&hot.room[de_rno].dyalloc);
		printf("\nEnter the number of persons");
		scanf("%d",&hot.room[de_rno].persons);
		if(hot.room[de_rno].rcat=='S'){
		  
		  bill_addper=hot.room[de_rno].persons-5;
		  hot.room[de_rno].rprice=1500;
		}
		else if(hot.room[de_rno].rcat=='D'){
		 
		  bill_addper=hot.room[de_rno].persons-5;
		  hot.room[de_rno].rprice=1000;
		}
		else if(hot.room[de_rno].rcat=='G'){
		  
		  bill_addper=hot.room[de_rno].persons-5;
		  hot.room[de_rno].rprice=750;
		}
		else if(hot.room[de_rno].rcat=='C'){
		  
		  bill_addper=hot.room[de_rno].persons-2;
		  hot.room[de_rno].rprice=1000;
		}
		else if(hot.room[de_rno].rcat=='E'){
		  
		  bill_addper=hot.room[de_rno].persons-2;
		  hot.room[de_rno].rprice=1500;
		}
		hot.room[de_rno].add_per=bill_addper;
		hot.room[de_rno].room_bill=(float)(hot.room[de_rno].rprice*hot.room[de_rno].dyalloc);
		hot.room[de_rno].cust.billo.restaraunt_bill=hot.room[de_rno].cust.res.tot_price;
		hot.room[de_rno].cust.billo.room_bill=hot.room[de_rno].room_bill;
		hot.room[de_rno].cust.billo.total_bill=hot.room[de_rno].cust.billo.room_bill+hot.room[de_rno].cust.billo.restaraunt_bill;
		printf("\nRestaraunt Bill is %4.4f",hot.room[de_rno].cust.billo.restaraunt_bill);
		printf("\nRoom Bill is %4.4f",hot.room[de_rno].cust.billo.room_bill);
		printf("\nTotal Bill is %4.4f",hot.room[de_rno].cust.billo.total_bill);
		float bill_paid=0;
		printf("\nEnter the amount paid");
		scanf("%f",&bill_paid);
		hot.room[de_rno].cust.billo.total_bill-=bill_paid;
		if(hot.room[de_rno].cust.billo.total_bill>0){
		  printf("Amount needs to be still paid %4.4f",hot.room[de_rno].cust.billo.total_bill);
		}
		printf("\nDealocate after total bill is paid");
		return 0;
	}
	
	else{
					printf("\nEnter a valid room no and customer id");
					billing();
				}
	  
	}
	
	
	int rtype;
	void rfeatures(void){
		printf("\nEnter the room type from below:");
		printf("\n1.Sp.delux\n2.Delux\n3.General\n4.Couple\n5.Couple Deluxe\n6.Main menu");
		scanf("%d",&rtype);
		switch(rtype)
	{
       case 1://clrscr();      
       printf("\n Room number            >>>1");       
       printf("\n                      FEATURES OF THIS ROOM                       ");       
       printf("\n\n Room Type            >>> Sp.delux");
       printf("\n\n Room charges         >>> Rs.1500 per day");
       printf("\n\n 1. Bed               >>>      2");
       printf("\n\n 2.Capacity           >>>      5");
       printf("\n\n 3.Balcony available     ");       
       printf("\n\n 1.A/C  available ");
       printf("\n\n 2.Geyser available");
       printf("\n\n 3.TV available      ");       
       break;
       
       case 2://clrscr();       
       printf("\n Room number            >>>2\n\n");       
       printf("\n                      FEATURES OF THIS ROOM                       ");       
       printf("\n\n Room Type            >>> Delux                                      ");
       printf("\n\n Room charges         >>>Rs.1000 per day");
       printf("\n\n 1. Bed               >>>      2");
       printf("\n\n 2.Capacity           >>>      5");       
       printf("\n\n 1.A/C available   ");
       printf("\n\n 2.Geyser available");
       printf("\n\n 3.TV available      ");       
       break;
       
       case 3://clrscr();       
       printf("\n Room number            >>>3\n\n");      
       printf("\n                      FEATURES OF THIS ROOM                       ");       
       printf("\n\n Room Type            >>> General                                    ");
       printf("\n\n Room charges         >>>Rs.750 per day");
       printf("\n\n 1. Bed               >>>      2");
       printf("\n\n 2.Capacity           >>>      5");       
       printf("\n\n 1.Geyser available      ");       
       break;
       
       case 4://clrscr();       
       printf("\n Room number            >>>4\n\n");       
       printf("\n                      FEATURES OF THIS ROOM                       ");       
       printf("\n\n Room Type            >>> Couple                                     ");
       printf("\n\n Room charges         >>>Rs.1000 per day");
       printf("\n\n 1. Bed               >>>      1");
       printf("\n\n 2.Capacity           >>>      2");       
       printf("\n\n 1.Geyser available");
       printf("\n\n 2.TV available      ");      
       break;
       
       case 5://clrscr();       
       printf("\n Room number            >>>5\n\n");       
       printf("\n                      FEATURES OF THIS ROOM                       ");       
       printf("\n\n Room Type            >>> Couple Delux                                    ");
       printf("\n\n Room charges         >>>Rs.1500 per day");
       printf("\n\n 1. Bed               >>>      1");
       printf("\n\n 2.Capacity           >>>      2");       
       printf("\n\n 1.A/C available   ");
       printf("\n\n 2.Geyser available");
       printf("\n\n 3.TV available      ");
       break;
       
	   case 6://clrscr();
				scr_menu(); break;
				
	   default: //clrscr();
				printf("\n Enter a vaild option");rfeatures();break;
	  
     }
	 	 rfeatures();
	}
	
	void scr_header(void){
		
	printf("\n\t                                FRASER SUITES ");
    printf("\n\t             Plot No - 4A, Kunchanapalli, near K L University, Guntur, INDIA");
    printf("\n\n                              Ph. No.:011-27223959");
    printf("\n\n\n                             WELCOMES YOU..............");
    }
	
	int choice=0;
	
	void scr_menu(void){
	
	do{
	  printf("\n\n--------Menu-----------");
                
					 printf("\n1.Get Availability");
					 printf("\n2.Features of room");
					 printf("\n3.Room allocation");
					 printf("\n4.Show customer details");
					 printf("\n5.Room deallocation");
					 printf("\n6.Restaurant");
					 printf("\n7.Billing");
					 printf("\n8.Exit");
	scanf("%d",&choice);
	int ch_rno,ch_custid;
	switch(choice){
		case 1: ravail();
		        break;
		case 2: rfeatures();
		        break;
		case 3: ralloc();
		        break;
		case 4: 
		        custde();
		        break;
		case 5: rdealloc();
		        break;
		case 6: rest();
		        break;
		case 7: billing();
				    break;
		case 8: exit(0);
		default : printf("\n Wrong user choice ");
		          break;
	}
	}while(choice!=8);
	
	}	//FOR DISPLAYING MENU
	
	
	
	int main(){		
		fflush(stdin);		
		//clrscr();
		intialize();				
		scr_header();
		scr_menu();		
		//getch();
		return 0;	
	}