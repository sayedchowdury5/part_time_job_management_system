//Preprocessor Directives

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include <math.h>
#include <time.h>

//structure definition for Jobpost
typedef struct Jobpost
{
    float pay;
    char date[20];
    char company[100];
    char address[100];
    char post[50];
    char workslot[50];
    char timeslot[50];
    char qualification[50];
}newJob;

//structure definition for Job Seeker
typedef struct Jobseeker
{
    int postcode;
    int contactno;
    char firstname[30];
    char lastname[50];
    char address[100];
    char city[50];
    char state[50];
    char email[100];
    char qualification1[50];
    char qualification2[50];
    char qualification3[50];
    char qualification4[50];
    char qualification5[50];
    char availability1[50];
    char availability2[50];
    char availability3[50];
    char availability4[50];
    char availability5[50];
}jobSeeker;

//function prototype declaration
void Mainmenu();  //display main menu
void CreateJob();    //display Jobpost screen
void AppendJob();    //display Jobpost screen
void CreateJobSeeker();      //display Jobseeker screen
void AppendJobSeeker();      //display Jobseeker screen
void Matching();   //display Matching availability
void Report();   //display Report
void terminate(); //exit programs

int main()
{
    system("COLOR F4");  //color display
	Mainmenu();//function call
}

//function definition for Main menu
void Mainmenu()

{   //variable declaration
    int select;
    system("cls");   //new screen
    printf("\t\t         Part-Time Job Seeking Management System\n");
    printf("\t\t----------------------------------\n");
    printf("\t\t----------------------------------\n\n");
    printf("\t\t----------------------------------\n");
    printf("\t\t---------OPTIONS FOR YOU---------\n");
    printf("\t\t----------------------------------\n");
    printf("1.Create Job\n2.Append Job\n3.Create Job Seeker\n4.Append Job Seeker\n5.Matching and Scheduling\n6.View Report\n7.Exit\n\n"); //display menu
    restart:
    printf("Please choose:\n");
    scanf("%d",&select);  //get input for choice
    getchar();

    switch(select)
    {
    //choice 1
    case 1:
        CreateJob(); //call CreateJob function
        break;     //break switch
    //choice 2
    case 2:
        AppendJob(); //call AppendJob function
        break;     //break switch
    //choice 3
    case 3:
        CreateJobSeeker(); //call CreateJobSeeker function
        break;     //break switch
    //choice 4
    case 4:
        AppendJobSeeker();   //call AppendJobSeeker function
        break;    //break switch
    //choice 5
    case 5:
        Matching(); //call Matching function
        break;     //break switch
    //choice 6
    case 6:
        Report(); //call Report function
        break;     //break switch
    //choice 7
    case 7:
      terminate(); //call terminate function
       break;      //break switch
    //if choice not 1-7
    default:
		printf("Wrong input.Please enter again\n");
		goto restart; //Back to choice again
		break;   //break switch

    }


}
//function definition for Job Post
void CreateJob()
{
    system("cls"); //new screen
    //variable declaration
    int noOfJobs,choose,input;
    newJob *job; //assign pointer for dynamic memory allocation

    printf("\t\t         Part-Time Job Seeking Management System\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t---------Post New Job Here---------\n");
    printf("\t\t-------------------------------------\n\n");
    printf("How many jobs you want to add? Please enter: ");
    scanf("%d",&noOfJobs);
    getchar();

    //allocate memory for no of jobs to job pointer
    job = (newJob*)calloc(noOfJobs, sizeof(newJob));

    FILE *outfile; //define file pointer 
    // open file for writing
    outfile = fopen ("jobs.dat", "w");
    if (outfile == NULL)
    {
        fprintf(stderr, "\nError opened file\n");
        exit (1);
    }
    for (int i = 0; i < noOfJobs; i++)
    {
        printf("Please Enter Details for %d job...\n",i+1);
        printf("Date: ");
        fgets(job[i].date, sizeof(job[i].date), stdin);
        printf("\nCompany: ");
        fgets(job[i].company, sizeof(job[i].company), stdin);
        printf("\n Address: ");
        fgets(job[i].address, sizeof(job[i].address), stdin);
        printf("\n Post: ");
        fgets(job[i].post, sizeof(job[i].post), stdin);
        printf("\n Work Slot: ");
        fgets(job[i].workslot, sizeof(job[i].workslot), stdin);
        printf("\n Time Slot: ");
        fgets(job[i].timeslot, sizeof(job[i].timeslot), stdin);
        printf("\n Pay: ");
        scanf("%f", &job[i].pay);
        getchar();
        printf("\n Qualification: ");
        printf("\n1.PMR\n2.SPM\n3.STPM/Diploma\n4.Degree\n5.Postgraduate\n");
        start:
        printf("Choose One: ");
        scanf("%d",&choose);
        getchar();
        if (choose == 1)
        {
            strcpy(job[i].qualification, "PMR");
        } else if(choose == 2)
        {
            strcpy(job[i].qualification, "SPM");
        } else if(choose == 3)
        {
            strcpy(job[i].qualification, "STPM/Diploma");
        } else if(choose == 4)
        {
            strcpy(job[i].qualification, "Degree");
        } else if(choose == 5)
        {
            strcpy(job[i].qualification, "Postgraduate");
        } else 
        {
            printf("Wrong selection! Try again please...\n");
            goto start;
        }
        
        // write struct to file
        fwrite (&job[i], sizeof(newJob), 1, outfile);
        
        if(fwrite != 0)
            printf("Your inputs are saved as new job post.\n\n");
        else
            printf("error writing file !\n");
    }
    // close file
    fclose (outfile);
    
    printf("Where Do you want to go Now?\n\n\t\t1.Main Menu\t\t\n\t\t2.Exit\n");
    again:
    printf("Input:");
    scanf("%d",&input);  //get input for either choice option
    printf("\n");

    if(input==1)
    {
        Mainmenu();  //call function
    }
    else if(input==2)
    {
        terminate();   //call function
    }
    else
    {
        printf("Wrong Input! input correctly.....\n");
        goto again;  // back to either choice option again
    }
}

//function definition for Job Post
void AppendJob()
{
    system("cls"); //new screen
    //variable declaration
    int noOfJobs,choose,input;
    newJob *job; //assign pointer for dynamic memory allocation

    printf("\t\t         Part-Time Job Seeking Management System\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t---------Add More Job Here---------\n");
    printf("\t\t-------------------------------------\n\n");
    printf("How many jobs you want to add? Please enter: ");
    scanf("%d",&noOfJobs);
    getchar();

    //allocate memory for no of jobs to job pointer
    job = (newJob*)calloc(noOfJobs, sizeof(newJob));

    FILE *outfile; //define file pointer 
    // open file for writing
    outfile = fopen ("jobs.dat", "a");
    if (outfile == NULL)
    {
        fprintf(stderr, "\nError opened file\n");
        exit (1);
    }
    for (int i = 0; i < noOfJobs; i++)
    {
        printf("Please Enter Details for %d job...\n",i+1);
        printf("Date: ");
        fgets(job[i].date, sizeof(job[i].date), stdin);
        printf("\nCompany: ");
        fgets(job[i].company, sizeof(job[i].company), stdin);
        printf("\n Address: ");
        fgets(job[i].address, sizeof(job[i].address), stdin);
        printf("\n Post: ");
        fgets(job[i].post, sizeof(job[i].post), stdin);
        printf("\n Work Slot: ");
        fgets(job[i].workslot, sizeof(job[i].workslot), stdin);
        printf("\n Time Slot: ");
        fgets(job[i].timeslot, sizeof(job[i].timeslot), stdin);
        printf("\n Pay: ");
        scanf("%f", &job[i].pay);
        getchar();
        printf("\n Qualification: ");
        printf("\n1.PMR\n2.SPM\n3.STPM/Diploma\n4.Degree\n5.Postgraduate\n");
        start:
        printf("Choose One: ");
        scanf("%d",&choose);
        getchar();
        if (choose == 1)
        {
            strcpy(job[i].qualification, "PMR");
        } else if(choose == 2)
        {
            strcpy(job[i].qualification, "SPM");
        } else if(choose == 3)
        {
            strcpy(job[i].qualification, "STPM/Diploma");
        } else if(choose == 4)
        {
            strcpy(job[i].qualification, "Degree");
        } else if(choose == 5)
        {
            strcpy(job[i].qualification, "Postgraduate");
        } else 
        {
            printf("Wrong selection! Try again please...\n");
            goto start;
        }
        
        // write struct to file
        fwrite (&job[i], sizeof(newJob), 1, outfile);
        
        if(fwrite != 0)
            printf("Your inputs are saved as new job post.\n\n");
        else
            printf("error writing file !\n");
    }
    // close file
    fclose (outfile);
    
    printf("Where Do you want to go Now?\n\n\t\t1.Main Menu\t\t\n\t\t2.Exit\n");
    again:
    printf("Input:");
    scanf("%d",&input);  //get input for either choice option
    printf("\n");

    if(input==1)
    {
        Mainmenu();  //call function
    }
    else if(input==2)
    {
        terminate();   //call function
    }
    else
    {
        printf("Wrong Input! input correctly.....\n");
        goto again;  // back to either choice option again
    }
}
//function definition for Job Seeker Details
void CreateJobSeeker()
{
    system("cls"); //new screen
    //variable declaration
    int noOfJobSeeker,choose,input,qualificationNo,availability;
    jobSeeker *jobSeek; //assign pointer for dynamic memory allocation

    printf("\t\t         Part-Time Job Seeking Management System\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t---------Add New Job Seeker Here---------\n");
    printf("\t\t-------------------------------------\n\n");
    printf("How many job seeker you want to add? Please enter: ");
    scanf("%d",&noOfJobSeeker);
    getchar();

    //allocate memory for no of jobseekers to jobSeek pointer
    jobSeek = (jobSeeker*)calloc(noOfJobSeeker, sizeof(jobSeeker));

    //save to file
    FILE *outfile; //define file pointer
    
    // open file for writing
    outfile = fopen ("jobSeekers.dat", "w");
    if (outfile == NULL)
    {
        fprintf(stderr, "\nError opened file\n");
        exit (1);
    }

    for (int i = 0; i < noOfJobSeeker; i++)
    {
        printf("Please Enter Details for %d Job Seeker...\n",i+1);
        printf("First Name: ");
        fgets(jobSeek[i].firstname, sizeof(jobSeek[i].firstname), stdin);
        printf("\n Last Name: ");
        fgets(jobSeek[i].lastname, sizeof(jobSeek[i].lastname), stdin);
        printf("\n Address: ");
        fgets(jobSeek[i].address, sizeof(jobSeek[i].address), stdin);
        printf("\n City: ");
        fgets(jobSeek[i].city, sizeof(jobSeek[i].city), stdin);
        printf("\n Postcode: ");
        scanf("%d", &jobSeek[i].postcode);
        getchar();
        printf("\n State: ");
        fgets(jobSeek[i].state, sizeof(jobSeek[i].state), stdin);
        printf("\n Contact No: ");
        scanf("%d", &jobSeek[i].contactno);
        printf("\n Email: ");
        getchar();
        fgets(jobSeek[i].email, sizeof(jobSeek[i].email), stdin);
        printf("\n Qualification: ");
        printf("\n1.PMR\n2.SPM\n3.STPM/Diploma\n4.Degree\n5.Postgraduate\n");
        printf("How many qualifications you have from the above lists? ");
        scanf("%d",&qualificationNo);
        getchar();
        for (int j = 0; j < qualificationNo; j++)
        {
            start:
            printf("Select No. %d qualification: ",j+1);
            scanf("%d",&choose);
            getchar();
            if (choose == 1)
            {
                strcpy(jobSeek[i].qualification1, "PMR");
            } else if(choose == 2)
            {
                strcpy(jobSeek[i].qualification2, "SPM");
            } else if(choose == 3)
            {
                strcpy(jobSeek[i].qualification3, "STPM/Diploma");
            } else if(choose == 4)
            {
                strcpy(jobSeek[i].qualification4, "Degree");
            } else if(choose == 5)
            {
                strcpy(jobSeek[i].qualification5, "Postgraduate");
            } else 
            {
                printf("Wrong selection! Try again please...\n");
                goto start;
            }
        }

        printf("\n Availability: ");
        printf("\n1.Flexible\n2.Daytime\n3.Evenings\n4.Weekdays\n5.Weekends\n");
        printf("How many availability you have from the above lists? ");
        scanf("%d",&availability);
        getchar();
        for (int k = 0; k < availability; k++)
        {
            restart:
            printf("Select No. %d availability: ",k+1);
            scanf("%d",&choose);
            getchar();
            if (choose == 1)
            {
                strcpy(jobSeek[i].availability1, "Flexible");
            } else if(choose == 2)
            {
                strcpy(jobSeek[i].availability2, "Daytime");
            } else if(choose == 3)
            {
                strcpy(jobSeek[i].availability3, "Evenings");
            } else if(choose == 4)
            {
                strcpy(jobSeek[i].availability4, "Weekdays");
            } else if(choose == 5)
            {
                strcpy(jobSeek[i].availability5, "Weekends");
            } else 
            {
                printf("Wrong selection! Try again please...\n");
                goto restart;
            }
        }
        // write struct to file
        fwrite (&jobSeek[i], sizeof( jobSeeker), 1, outfile);
        
        if(fwrite != 0)
            printf("Your inputs are saved as new job seeker.\n\n");
        else
            printf("error writing file !\n");
    }
    // close file
    fclose (outfile);

    printf("Where Do you want to go Now?\n\n\t\t1.Main Menu\t\t\n\t\t2.Exit\n");
    again:
    printf("Input:");
    scanf("%d",&input);  //get input for either choice option
    printf("\n");

    if(input==1)
    {
        Mainmenu();  //call function
    }
    else if(input==2)
    {
        terminate();   //call function
    }
    else
    {
        printf("Wrong Input! input correctly.....\n");
        goto again;  // back to either choice option again
    }
}

//function definition for Job Seeker Details
void AppendJobSeeker()
{
    system("cls"); //new screen
    //variable declaration
    int noOfJobSeeker,choose,input,qualificationNo,availability;
    jobSeeker *jobSeek; //assign pointer for dynamic memory allocation

    printf("\t\t         Part-Time Job Seeking Management System\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t---------Add More Job Seeker Here---------\n");
    printf("\t\t-------------------------------------\n\n");
    printf("How many job seeker you want to add? Please enter: ");
    scanf("%d",&noOfJobSeeker);
    getchar();

    //allocate memory for no of jobseekers to jobSeek pointer
    jobSeek = (jobSeeker*)calloc(noOfJobSeeker, sizeof(jobSeeker));

    //save to file
    FILE *outfile; //define file pointer
    
    // open file for writing
    outfile = fopen ("jobSeekers.dat", "a");
    if (outfile == NULL)
    {
        fprintf(stderr, "\nError opened file\n");
        exit (1);
    }

    for (int i = 0; i < noOfJobSeeker; i++)
    {
        printf("Please Enter Details for %d Job Seeker...\n",i+1);
        printf("First Name: ");
        fgets(jobSeek[i].firstname, sizeof(jobSeek[i].firstname), stdin);
        printf("\n Last Name: ");
        fgets(jobSeek[i].lastname, sizeof(jobSeek[i].lastname), stdin);
        printf("\n Address: ");
        fgets(jobSeek[i].address, sizeof(jobSeek[i].address), stdin);
        printf("\n City: ");
        fgets(jobSeek[i].city, sizeof(jobSeek[i].city), stdin);
        printf("\n Postcode: ");
        scanf("%d", &jobSeek[i].postcode);
        getchar();
        printf("\n State: ");
        fgets(jobSeek[i].state, sizeof(jobSeek[i].state), stdin);
        printf("\n Contact No: ");
        scanf("%d", &jobSeek[i].contactno);
        printf("\n Email: ");
        getchar();
        fgets(jobSeek[i].email, sizeof(jobSeek[i].email), stdin);
        printf("\n Qualification: ");
        printf("\n1.PMR\n2.SPM\n3.STPM/Diploma\n4.Degree\n5.Postgraduate\n");
        printf("How many qualifications you have from the above lists? ");
        scanf("%d",&qualificationNo);
        getchar();
        for (int j = 0; j < qualificationNo; j++)
        {
            start:
            printf("Select No. %d qualification: ",j+1);
            scanf("%d",&choose);
            getchar();
            if (choose == 1)
            {
                strcpy(jobSeek[i].qualification1, "PMR");
            } else if(choose == 2)
            {
                strcpy(jobSeek[i].qualification2, "SPM");
            } else if(choose == 3)
            {
                strcpy(jobSeek[i].qualification3, "STPM/Diploma");
            } else if(choose == 4)
            {
                strcpy(jobSeek[i].qualification4, "Degree");
            } else if(choose == 5)
            {
                strcpy(jobSeek[i].qualification5, "Postgraduate");
            } else 
            {
                printf("Wrong selection! Try again please...\n");
                goto start;
            }
        }

        printf("\n Availability: ");
        printf("\n1.Flexible\n2.Daytime\n3.Evenings\n4.Weekdays\n5.Weekends\n");
        printf("How many availability you have from the above lists? ");
        scanf("%d",&availability);
        getchar();
        for (int k = 0; k < availability; k++)
        {
            restart:
            printf("Select No. %d availability: ",k+1);
            scanf("%d",&choose);
            getchar();
            if (choose == 1)
            {
                strcpy(jobSeek[i].availability1, "Flexible");
            } else if(choose == 2)
            {
                strcpy(jobSeek[i].availability2, "Daytime");
            } else if(choose == 3)
            {
                strcpy(jobSeek[i].availability3, "Evenings");
            } else if(choose == 4)
            {
                strcpy(jobSeek[i].availability4, "Weekdays");
            } else if(choose == 5)
            {
                strcpy(jobSeek[i].availability5, "Weekends");
            } else 
            {
                printf("Wrong selection! Try again please...\n");
                goto restart;
            }
        }
        // write struct to file
        fwrite (&jobSeek[i], sizeof( jobSeeker), 1, outfile);
        
        if(fwrite != 0)
            printf("Your inputs are saved as new job seeker.\n\n");
        else
            printf("error writing file !\n");
    }
    // close file
    fclose (outfile);

    printf("Where Do you want to go Now?\n\n\t\t1.Main Menu\t\t\n\t\t2.Exit\n");
    again:
    printf("Input:");
    scanf("%d",&input);  //get input for either choice option
    printf("\n");

    if(input==1)
    {
        Mainmenu();  //call function
    }
    else if(input==2)
    {
        terminate();   //call function
    }
    else
    {
        printf("Wrong Input! input correctly.....\n");
        goto again;  // back to either choice option again
    }
}

//function definition for Matching and Scheduling ability
void Matching()
{
    system("cls");  //new screen
    //variable declaration
    int noOfJobs,noOfJobSeekers,next;
    newJob job;
    jobSeeker jobSeek;

    printf("\t\t         Part-Time Job Seeking Management System\n");
    printf("\t\t----------------------------------\n");
    printf("\t\t----------------------------------\n\n");
    printf("\t\t Matching and Scheduling\n\n");

    //read file
    FILE *jobsFile; //file pointer
    FILE *jobSeekersFile; //file pointer
     
    // Open files for reading
    jobsFile = fopen ("jobs.dat", "r");
    jobSeekersFile = fopen ("jobSeekers.dat", "r");
    if (jobsFile == NULL || jobSeekersFile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }

    fseek(jobsFile, 0, SEEK_END);
    noOfJobs = ftell(jobsFile)/sizeof(newJob);
    //job = (newJob*)calloc(noOfJobs, sizeof(newJob)); //allocate memory to job pointer
    fseek(jobSeekersFile, 0, SEEK_END);
    noOfJobSeekers = ftell(jobSeekersFile)/sizeof(jobSeeker);
    //jobSeek = (jobSeeker*)calloc(noOfJobSeekers, sizeof(jobSeeker)); //allocate memory to jobSeek pointer
    fseek(jobsFile, 0L, SEEK_SET);
    fseek(jobSeekersFile, 0L, SEEK_SET);
    
    // for (int i = 0; i < noOfJobs; i++)
    // {
    //     fread(&job[i], sizeof(newJob), 1, jobsFile);
    // }
    // for (int i = 0; i < noOfJobSeekers; i++)
    // {
    //     fread(&jobSeek[i], sizeof(jobSeeker), 1, jobSeekersFile);
    // }

    //display matching
    // read file contents till end of file 
    while(fread(&job, sizeof(newJob), 1, jobsFile))
    {
        char firstname[50];
        char lastname[50];
        while (fread(&jobSeek, sizeof(jobSeeker), 1, jobSeekersFile))
        {
            if (
                strcmp(job.qualification, jobSeek.qualification1) == 0 ||
                strcmp(job.qualification, jobSeek.qualification2) == 0 ||
                strcmp(job.qualification, jobSeek.qualification3) == 0 ||
                strcmp(job.qualification, jobSeek.qualification4) == 0 ||
                strcmp(job.qualification, jobSeek.qualification5) == 0
                )
            {
                strcpy(firstname,jobSeek.firstname);
                strcpy(lastname,jobSeek.lastname);

            }
        }
        printf(" Company: %s\n Post: %s\n Day: %s\n Time: %s\n Job Seeker: %s %s\n\n", job.company, job.post, job.workslot, job.timeslot, firstname, lastname);
        printf("----------------------------------------------------\n\n");
        
    } 
    // close files
    fclose (jobsFile);
    fclose (jobSeekersFile);

    printf("Where Do you want to go Now?\n\n\t\t1.Main Menu\t\t\n\t\t2.Exit\n");
    cust:
    printf("Your choice: ");
    scanf("%d",&next);  //get input for either choice option
    if(next==1)
    {
        Mainmenu();  //call function
    }
    else if(next==2)
    {
        terminate();  //call function
    }
    else
    {
        printf("Wrong Input! Please Re-Input....\n");
        goto cust;  //back for either choice option again
    }

}

//function definition for displaying Report
void Report()
{
    system("cls");  //new screen
    //variable declaration
    int noOfJobs,noOfJobSeekers,jobless,next;
    newJob job;
    jobSeeker jobSeek;

    printf("\t\t         Part-Time Job Seeking Management System\n");
    printf("\t\t----------------------------------\n");
    printf("\t\t----------------------------------\n\n");
    printf("\t\t Monthly Job Listing Report\n\n");

    //read file
    FILE *jobsFile; //file pointer
    FILE *jobSeekersFile; //file pointer
     
    // Open files for reading
    jobsFile = fopen ("jobs.dat", "r");
    jobSeekersFile = fopen ("jobSeekers.dat", "r");
    if (jobsFile == NULL || jobSeekersFile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }
    fseek(jobsFile, 0, SEEK_END);
    noOfJobs = ftell(jobsFile)/sizeof(newJob);

    fseek(jobSeekersFile, 0, SEEK_END);
    noOfJobSeekers = ftell(jobSeekersFile)/sizeof(jobSeeker);

    jobless = abs(noOfJobs-noOfJobSeekers);
    fseek(jobsFile, 0L, SEEK_SET);
    fseek(jobSeekersFile, 0L, SEEK_SET);
    
    
     
    // read file contents till end of file
    while(fread(&job, sizeof(newJob), 1, jobsFile))
    {
        while (fread(&jobSeek, sizeof(jobSeeker), 1, jobSeekersFile))
        {
            printf(" Month: %s\n Total Job: %d\n Total Job Seeker: %d\n Qualification:\n\t\tPMR: %d\n\t\tSPM: %d\n\t\tSTPM/Diploma: %d\n\t\tDegree/Postgraduate: %d\n Highest Paid: RM %.2f/hr - %s\n Lowest Paid: RM %.2f/hr - %s\n Jobless: %d\n\n", "January 2022", noOfJobs, noOfJobSeekers, 1,1,1,1, job.pay, job.company, job.pay, job.company, jobless);
            printf("----------------------------------------------------\n\n");
        }
        
    } 
    // close files
    fclose (jobsFile);
    fclose (jobSeekersFile);

    printf("Where Do you want to go Now?\n\n\t\t1.Main Menu\t\t\n\t\t2.Exit\n");
    cust:
    printf("Your choice: ");
    scanf("%d",&next);  //get input for either choice option
    if(next==1)
    {
        Mainmenu();  //call function
    }
    else if(next==2)
    {
        terminate();  //call function
    }
    else
    {
        printf("Wrong Input! Please Re-Input....\n");
        goto cust;  //back for either choice option again
    }

}
//function definition for terminate
void terminate()
{
    system("cls");
    printf("\t\t         Part-Time Job Seeking Management System\n");
    printf("\t\t----------------------------------\n");
    printf("\t\t----------------------------------\n\n");

    printf("Thank You For Using Our System.\n\n");
    printf("Have a Nice Day!\n\n\n");
    exit(0); //program exit
}