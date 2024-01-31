#include <iostream>
#include <algorithm>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<iomanip> 
#include<climits> 
#include<windows.h>
using namespace std;
 
int total=0;
struct Process
{
  	int pid;;
    int AT;
    int BT;
    int ST;
    int CT;
    int TAT;
    int WT;
    int RT;  

  string Name;
  string status;
  string priority;   
}PS[100];


bool comparatorAT(struct Process a,struct Process b)
{
   int x =a.AT;
   int y =b.AT;
   return x < y;
}  

bool comparatorPID(struct Process a,struct Process b)
{
   int x =a.pid;
   int y =b.pid;
   return x < y;
}


//this function get details of the process from the
//user...
void getdata(int num){
	int i=total;
	num+=total;

			    for( i;i<num;i++)
			    {
			    PS[i].priority="high";
    	        PS[i].pid=i;
    	        cout<<"\n=============================================="<<endl;
    			cout<<"Process id is :"<<PS[i].pid<<endl;
    			PS[i].status="ready";
				cout<<"Process Status is : "<<PS[i].status<<endl;
			    cout<<"================================================="<<endl;
			    cout<<"_____"<<endl;
			    cout<<"\nEnter Process no " <<i<< "| Process Name : ";
			    cin >>PS[i].Name; 
			    cout<<"\nEnter Process no " <<i<< "| Arrival Time : ";
			    cin >> PS[i].AT;
			    cout<<"\nEnter Process no " <<i<< "| Burst Time : ";
			    cin >> PS[i].BT;
			    cout<<"\n_______"<<endl;
			    total++;
			    }				    
			    
}

//This function show the PCB
void showprocess(int num){
cout<<"\nProcess-No.\tName\tAT\tBT"<<endl;
	for(int i=0;i<num;i++)
	{
		cout<<i<<"\t\t"<<PS[i].Name<<"\t"<<PS[i].AT<<"\t"<<PS[i].BT<<"\t"<<endl;

	}
}

//this Function delete the process
void destroyprocess(int num){
	int list=0;
	for(int i=0;i<num;i++){
		if(PS[i].pid >= 0){
			list++;
		}
	}
	if(list > 0){
		showprocess(total);
		cout<<"=============================================="<<endl;
		string name;
		int found=0;
		cout<<"\nEnter Process Name to Delete: ";
	    cin>>name;
	    for(int i=0; i<total; i++)
	    {
	        if(PS[i].Name==name)
	        {
	        	found++;
	            for(int j=i; j<(total-1); j++)
	                PS[j] = PS[j+1];
	            found++;
	            i--;
	            total--;
	        }
	    }
	    if(found==0)
	        cout<<"\nElement doesn't found in the Array!";
	    else
	        cout<<"\nElement Deleted Successfully!";
	    cout<<endl;
	}
	else{
		cout<<"No Available Processes."<<endl;
	}
}

//This function Suspend the process
void suspendprocess(int num){
	int list=0;
	for(int i=0;i<num;i++){
		if(PS[i].pid >= 0){
			list++;
		}
	}
	
	if(list > 0){
		showprocess(total);
		string name;
		int found=0;
		cout<<"\nEnter Process Name to Suspend: ";
	    cin>>name;
	    
	    for(int i=0; i<total; i++)
	    {
	        if(PS[i].Name==name)
	        {
	        	found++;
	            PS[i].status = "suspend";
	            PS[i].priority = "medium";
	        }
	    }
	    if(found==0)
	        cout<<"\nElement doesn't found in the Array!";
	    else
	        cout<<"\nElement Suspended Successfully!";
	    cout<<endl;
	}
	else{
		cout<<"No Available Process."<<endl;
	}		
}
void dispatch()
{
	cout<<"Nothing "<<endl;
}

//This function resume the process.
void resumeprocess(int num){
	string name;
	int found=0;
	int list=0;
	for(int i=0;i<num;i++)
	{
		if(PS[i].status=="suspend"){
			list++;
		}
	}
	if(list > 0){
	    cout<<"\nP-No.\tName\tAT\tBT\n";
				for(int i=0;i<num;i++)
		{
			if(PS[i].status=="suspend"){
			cout<<PS[i].pid<<"\t"<<PS[i].Name<<"\t"<<PS[i].AT<<"\t"<<PS[i].BT<<endl;	
			}
		}
		cout<<"=============================================="<<endl;
		
		cout<<"\nEnter Process Name to Resume: ";
	    cin>>name;
	    for(int i=0; i<total; i++)
	    {
	        if(PS[i].Name==name)
	        {
	        	found++;
	            PS[i].status = "ready";
	            PS[i].priority = "high";
	        }
	    }
	    if(found==0)
	        cout<<"\nElement doesn't found in the Array!";
	    else
	        cout<<"\nElement Resumed Successfully!";
	    cout<<endl;
	}
	else{
		cout<<"No Suspended Processes."<<endl;
	}
}

//This function Block the process i/o exception
void blockprocess(int num){
	int list=0;
	for(int i=0;i<num;i++){
		if(PS[i].pid>=0){
			list++;
		}
	}
	
	if(list > 0){
		showprocess(total);
		cout<<"=========================================="<<endl;
		string name;
		int found=0;
		cout<<"\nEnter Process Name to Block: ";
	    cin>>name;
	    for(int i=0; i<total; i++)
	    {
	        if(PS[i].Name==name)
	        {
	        	found++;
	           PS[i].status = "block";
	            PS[i].priority = "low";
	        }
	    }
	    if(found==0)
	        cout<<"\nElement doesn't found in the Array!";
	    else
	        cout<<"\nElement Blocked Successfully!";
	    cout<<endl;
	}
	else{
		cout<<"No Available Process."<<endl;
	}
}
void changepriority(){
	cout<<"Nothing"<<endl;
}


//this function Wakeup the process
void wakeupprocess(int num){
	string name;
	int found=0;
	int list=0;
	for(int i=0;i<num;i++)
	{
		if(PS[i].status=="block"){
			list++;
		}
	}
	if(list > 0){
		cout<<"Process Number\tArrival Time\tBurst Time\n";
		for(int i=0;i<num;i++)
		{
			if(PS[i].status=="block"){
				cout<<PS[i].pid<<"\t\t"<<PS[i].AT<<"\t\t"<<PS[i].BT<<endl;		
			}
		}
		cout<<"======================================================"<<endl;

		cout<<"\nEnter Process Name to Resume: ";
	    cin>>name;
	    for(int i=0; i<total; i++)
	    {
	        if(PS[i].status=="block"){
	        	if(PS[i].Name==name)
		        {
		        	found++;
		            PS[i].status = "ready";
		            PS[i].priority = "high";
		        }
			}
			else{
				goto found0;
			}
	    }
	    if(found==0)
	    found0:
	        cout<<"\nElement doesn't found in the Array!";
	    else
	        cout<<"\nElement Resumed Successfully!";
	    cout<<endl;
	}
	else{
		cout<<"No Blocked Processes."<<endl;
	}
}

//fuction of first come first serve 
void fcfs(int num){
	
	 float sum_TAT=0,sum_WT=0,sum_RT=0;
			    int length_cycle,total_idle_time=0;
			    sort(PS,PS+num, comparatorAT);
			
			    for(int i=0;i<num;i++)
			    {
			      PS[i].ST = (i==0) ? PS[i].AT : max(PS[i].AT, PS[i-1].CT);  
			      PS[i].CT =  PS[i].ST + PS[i].BT;
			      PS[i].TAT = PS[i].CT-PS[i].AT;       
			      PS[i].WT = PS[i].TAT-PS[i].BT;
			      PS[i].RT=PS[i].WT;
			       
			      sum_TAT += PS[i].TAT;
			      sum_WT += PS[i].WT;
			      sum_RT += PS[i].RT;
			      total_idle_time += (i==0) ? 0 : (PS[i].ST -  PS[i-1].CT);
			    }
			    length_cycle = PS[num-1].CT - PS[0].ST;
			    sort(PS,PS+num, comparatorPID);
			    
			    cout<<"______"<<endl;
			    cout<<"\nP-No.\tName\tAT\tBT\tCT\tTAT\tWT\tRT\n";
			    cout<<"______"<<endl;
			    for(int i=0;i<num;i++)
			     cout<<i<<"\t"<<PS[i].Name<<"\t"<<PS[i].AT<<"\t"<<PS[i].BT<<"\t"<<PS[i].CT<<"\t"<<PS[i].TAT<<"\t"<<PS[i].WT<<"\t"<<PS[i].RT<<endl;
			    cout<<"______"<<endl;
			    cout<<endl;
			   
			    
	
}

//ROUND ROBIN
void findWaitingTime(int processes[], int n, 
			int bt[], int wt[], int quantum) 
{ 
	// Make a copy of burst times bt[] to store remaining 
	// burst times. 
	int rem_bt[n]; 
	for (int i = 0 ; i < n ; i++) 
		rem_bt[i] = bt[i]; 
	int t = 0; // Current time 
	// Keep traversing processes in round robin manner 
	// until all of them are not done. 
	while (1) 
	{ 
		bool done = true; 
		// Traverse all processes one by one repeatedly 
		for (int i = 0 ; i < n; i++) 
		{ 
			// If burst time of a process is greater than 0 
			// then only need to process further 
			if (rem_bt[i] > 0) 
			{ 
				done = false; // There is a pending process 
				if (rem_bt[i] > quantum) 
				{ 
					// Increase the value of t i.e. shows 
					// how much time a process has been processed 
					// Decrease the burst_time of current process 
					// by quantum 
					rem_bt[i] -= quantum; 
				} 
				// If burst time is smaller than or equal to 
				// quantum. Last cycle for this process 
				else
				{ 
					// Increase the value of t i.e. shows 
					// how much time a process has been processed 
					t = t + rem_bt[i]; 
					// Waiting time is current time minus time 
					// used by this process 
					wt[i] = t - bt[i]; 
					// As the process gets fully executed 
					// make its remaining burst time = 0 
					rem_bt[i] = 0; 
				} 
			} 
		} 
		// If all processes are done 
		if (done == true) 
		break; 
	} 
} 
// Function to calculate turn around time 
void findTurnAroundTime(int processes[], int n, 
						int bt[], int wt[], int tat[]) 
{ 
	// calculating turnaround time by adding 
	// bt[i] + wt[i] 
	for (int i = 0; i < n ; i++) 
		tat[i] = bt[i] + wt[i]; 
} 
// Function to calculate average time 
void findavgTime(int processes[], int n, int bt[], 
									int quantum) 
{ 
	int wt[n], tat[n], total_wt = 0, total_tat = 0; 
	// Function to find waiting time of all processes 
	findWaitingTime(processes, n, bt, wt, quantum); 
	// Function to find turn around time for all processes 
	findTurnAroundTime(processes, n, bt, wt, tat); 
	// Display processes along with all details 
	cout << "Processes "<< " Burst time "
		<< " Waiting time " << " Turn around time\n"; 
	// Calculate total waiting time and total turn 
	// around time 
	for (int i=0; i<n; i++) 
	{ 
		total_wt = total_wt + wt[i]; 
		total_tat = total_tat + tat[i]; 
		cout << " " << i+1 << "\t\t" << bt[i] <<"\t "
			<< wt[i] <<"\t\t " << tat[i] <<endl; 
	} 
	cout << "Average waiting time = "
		<< (float)total_wt / (float)n; 
	cout << "\nAverage turn around time = "
		<< (float)total_tat / (float)n; 
}

//calculate the average
void Avergecalculator(int num){

	     fcfs(num);
	   	    float sum_TAT=0,sum_WT=0,sum_RT=0;
	   	        cout<<"\nAVERAGE TURN-AROUND-TIME : "<< sum_TAT/num;
                cout<<"\nAVERAGE WAITING TIME :"<<sum_WT/num;
                cout<<"\nAVEARGE RESPONSE TIME : "<<sum_RT/num/num;
                cout<<endl;

}
int main()
{
	system("cls"); //it clear the previous console
	cout<<"\n\n\t\t\t		------------------------	"<<endl;
	cout<<"\n\n\t\t\t |		OPERATING SYSTEM PROJECT		|"<<endl;
	cout<<"\n\n\t\t\t		------------------------	"<<endl;
	cout<<"\n\n\t\t\t |		PROCESS CONTROL BLOCK			|	"<<endl;
	cout<<"\n\n\t\t\t		------------------------	"<<endl;
	cout<<"\n\tMade by:";
	cout<<"\n\t\t\t 		Hamayun zafar "<<endl;
	cout<<"\n\t\t\t 		mohsin raza "<<endl;
	cout<<"\n\t presented  to:\t 		MAM Dua Mahmood "<<endl;
	Sleep(3000);//it pause the screen for  second
	system("cls");
	
{

	menu:
	int n;
    cout<<"                                        "<<endl<<endl;
	cout<<"Enter   1 Process Management          "<<endl;
	cout<<"Enter   2 Memory Management           "<<endl;
	cout<<"Enter   3 Scheduling            "<<endl;
	

	cout<<"Enter   0 Exit                        "<<endl;
 cout<<"Enter : ";
	cin>>n;
	system("cls");

	switch(n){
		case 1:
	    	cout<<"                                            "<<endl<<endl;
			cout<<"         PROCESS MANAGEMENT            "<<endl<<endl;
			cout<<"Enter   1 for  Create a Process           "<<endl;
			cout<<"Enter    2 for Destory a Process          "<<endl;
			cout<<"Enter    3 for Suspend a Process          "<<endl;
			cout<<"Enter    4 for Resume a Process           "<<endl;
			cout<<"Enter    5 for Block a Process            "<<endl;
			cout<<"Enter    6 for Wakeup a Process           "<<endl;
			cout<<"Enter    7 for Dispatch a Process         "<<endl;
			cout<<"Enter    8 for Change Process Priority    "<<endl;
			cout<<"Enter    9 for Process Communication      "<<endl;
			cout<<"Enter    0 for Back                       "<<endl;
		

			cin>>n;
			switch(n){
			case 1:
					 cout<<"Create Process "<<endl<<endl;
					int num;
					cout<<endl;
				    cout << "Enter Total Number of Processes: ";
				    cin >> num;
				    cout<<endl;
					getdata(num);
					   cout<<"Press-> 0 for Back";
					cin>>n;
					switch(n){
						case 0:
						goto menu;
						break;
					}
			break;
			case 2:
                         cout<<"Destry a Process"<<endl<<endl;
					destroyprocess(total);	
					cout<<"Press-> 0 for Back";                    
					cin>>n;
					
					switch(n){
						case 0:
						goto menu;
						break;
					}
				break;
			
			case 3:
					cout<<"Suspend a process "<<endl<<endl;
					suspendprocess(total);
					cout<<"Press-> 0 for Back"; 
					cin>>num;
					
					switch(num){
						case 0:
						goto menu;
			break;
		}
		break;
			case 4:
					cout<<"Resume a process "<<endl<<endl;
					resumeprocess(total);
				 cout<<"Press-> 0 for Back"; 
					cin>>num;
					
					switch(num){
						case 0:
						goto menu;
						break;
					}
			break;
			case 5:
					cout<<"Block a Process "<<endl<<endl;
					blockprocess(total);
					cout<<"Press-> 0 for Back"; 
					cin>>num;
					
					switch(num){
						case 0:
						goto menu;
						break;
					}
					break;
			break;
			case 6:
					cout<<"Wake Up A process "<<endl<<endl;
					wakeupprocess(total);
				     cout<<"Press-> 0 for Back"; 
					cin>>num;
					
					switch(num){
						case 0:
						goto menu;
						break;
					}
					break;
			case 7:
					  cout<<"Dispatch a process "<<endl<<endl;
					  dispatch();
					cout<<"Press-> 0 for Back"; 		
					cin>>num;
					
					switch(num){
						case 0:
					goto menu;
						break;
					}
			break;
				case 8:
			        cout<<"Change Process Priority"<<endl;				
					changepriority();
			        cout<<"[0] Back"<<endl;			
					cin>>num;
					
					switch(num){
						case 0:
						goto menu;
						break;
					}
			break;
			case 9:
					cout<<"Process Communication"<<endl;
			        cout<<"[0] Back"<<endl;
					cin>>num;
					
					switch(num){
						case 0:
						goto menu;
						break;
					}
			break;
			case 0:
			goto menu;
			break;
			
			}
			break;
		case 2:
			cout<<"MEMORY MANAGEMENT"<<endl;
			cout<<"[1] PAGING"<<endl;			
			cout<<"[2] LRU"<<endl;
			cout<<"[0] Back"<<endl;					
			cin>>n;
					
					switch(n){
						case 1:
						{
 int ms, ps, nop, np, rempages, i, j, x, y, pa, offset;
 int s[100], fno[100][100];

printf("\nEnter the memory size -- ");
scanf("%d",&ms);

printf("\nEnter the page size -- ");
scanf("%d",&ps);

nop = ms/ps;
printf("\nThe no. of pages available in memory are -- %d ",nop);

printf("\nEnter number of processes -- ");
 scanf("%d",&np);
rempages = nop;
for(i=1;i<=np;i++)

{

printf("\nEnter no. of pages required for p[%d]-- ",i);
 scanf("%d",&s[i]);

if(s[i] >rempages)
{

printf("\nMemory is Full");
break;
}
rempages = rempages - s[i];

printf("\nEnter page table for p[%d] --- ",i);
 for(j=0;j<s[i];j++)
scanf("%d",&fno[i][j]);
}

printf("\nEnter Logical Address to find Physical Address ");
printf("\nEnter process no. and pagenumber and offset -- ");

scanf("%d %d %d",&x,&y, &offset);



if(x>np || y>=s[i] || offset>=ps)
printf("\nInvalid Process or Page Number or offset");

else
{ pa=fno[x][y]*ps+offset;
printf("\nThe Physical Address is -- %d",pa);

}
getch();
}
system("cls");
goto menu;
						break;
			case 2:
			int nopages, nofaults, page[20],i ,count=0;
			cout<<"Least Recently Used"<<endl;	
            cout<<"\n Enter the No of Pages :"; 
            cin>> nopages;  //it will store the number of Pages
            cout<<"\n Enter the Reference String :";
            for(i=0;i< nopages;i++)
            {
            cout<<"\t"; 
            cin>>page[i];
            }   
            
            cout<<"\n Enter the Number of Frames :"; 
            cin>> nofaults;
            int frame[nofaults],fcount[nofaults];
            for(i=0;i< nofaults;i++)
            {
            frame[i]=-1;
            fcount[i]=0; //it will keep the track of when the page was last used
            }
            i=0;
            while(i< nopages)
            {
                int j=0,flag=0;
                while(j< nofaults)
                {
                if(page[i]==frame[j]){  //it will check whether the page already exist in frames or not
                flag=1;
                fcount[j]=i+1;
                }
                j++;
                }   
                j=0;  
                cout<<"\n\t-----------------------------------------------------------------------------------------------------\n";
                cout<<"\t"<<page[i]<<"~";   
                if(flag==0)
                {
                int min=0,k=0;
                while(k<nofaults-1) 
                { 
                    if(fcount[min]>fcount[k+1]) //It will calculate the page which is least recently used
                    min=k+1;
                    k++;
                    }
                frame[min]=page[i]; 
                fcount[min]=i+1;  //Increasing the time
                count++;           //it will count the total Page Fault
                while(j< nofaults)
                {
                cout<<"\t|"<<frame[j]<<"|";
                j++;
                }
                }
            i++; 
            }
            cout<<"\n\t------------------------------------------------------------------------------------------------------------\n";
            cout<<"\n Page Fault :"<<count<<endl;
               goto menu;
            break;
        }
		break;
        
		case 3:
			
			cout<<"Enter 1 for  FIRST COME FIRST SERVE             "<<endl;
			cout<<"Enter 2 for  ROUND ROBIN              "<<endl;
			cout<<"Enter 0 for   Back            "<<endl;
	
			cin>>n;
			switch(n){ 
		
			case 1:
		
	                   cout<<"                    FCFS                "<<endl<<endl;
		                fcfs(total);

			  cout<<"          Calculate Average            "<<endl;
	            cout<<"                                     "<<endl;
	            cout<<"       [1] Average TAT, WT, RT       "<<endl;
	            cout<<"       [0] Back                      "<<endl;
	         
	            cin>>n;
			    
			    switch(n) {	
			     case 1:
			    Avergecalculator(total);
			        cout<<"               Enter 0 for  Back              "<<endl;
					
					cin>>n;
					
					switch(n){
						case 0:
						goto menu;
						break;
					}
		
				break;
				case 0:
					cout<<"Enter 0 for Back"<<endl;					
					cin>>n;
					
					switch(n){
						case 0:
						goto menu;
						break;
					}
					break;
				}
					cout<<"Enter 0 for Back";					
					cin>>n;
					
					switch(n){
						case 0:
						goto menu;
						break;
					}
		
		          break;
		 	
		 case 2:
{ 
	// process id's 
	int process[] = { 1, 2,3,4,5}; 
	int n = sizeof process / sizeof process[0]; 
	// Burst time of all processes 
	int BT[] = {10, 5,7,8,3,}; 
	// Time quantum 
	int quantum = 2; 
	findavgTime(process, n,BT, quantum); 
	return 0; 
			break;
			
		}
		goto menu;
		case 3:
			goto menu;
			break;
		} 
		break;
	
	          case 4:
	          	cout<<"Nothing"<<endl;
			      cout<<"Enter 0 for Back "<<endl;
			      goto menu;
			    cin>>n;
			  goto menu;
			
			break;
				
           		case 0:
           			cout<<"Exit";
           			break;
           		}
			    return 0;
			}
		}
