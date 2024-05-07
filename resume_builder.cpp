#include <iostream>
#include<fstream>
//#include<ofstream>
#include<algorithm>
#include<math.h>
#include<windows.h>
#include<vector>
#include<string>

//ofstream outfile("file1.txt",ios::app);
//outfile.open("file1.txt", ios::out);

using namespace std;
string id,id_;
/*void changeColor(int desiredColor){

     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor);
}*/

bool check_mob(long long mobile)
{

    int i=0;
    while(mobile>0)
    {
        mobile = mobile /10;
        i++;
    }
    if(i==10)
        return true;
    else
        return false;
}

bool check_email(string email)
{

    for(int i=0;email[i]!='\0' ; i++)
    {
        if(email[i]=='@')
            return true;
    }
    return false;
}

class education
{
    public:
    string school_name;
    string degree_name;
    vector<string> other_info;
    string completion_year;
    string place;

    void print_edu(ofstream& outfile)
    {

        //changeColor(6);
        cout<<"\n"<<school_name<<"\n";
        cout<<place<<"\n";
        outfile<<"\n"<<school_name<<"\n";
        outfile<<place<<"\n";
        //changeColor(7);
        cout<<degree_name<<"\t\t\t\t"<<completion_year;
        outfile<<degree_name<<"\t\t\t\t"<<completion_year;
        int i=0;
        while(i<int(other_info.size()))
        {
            cout<<"\n"<<other_info.at(i);
            outfile<<"\n"<<other_info.at(i);
            i++;

        }
        cout<<"\n";
        outfile<<"\n";

    }
};


class expirence
{
    public:
    string company_name;
    string position;
    vector<string> work_info;
    string tenure;
    string place;

    void print_exp(ofstream& outfile)
    {

        //changeColor(6);
        cout<<"\n"<<company_name<<"\n";
        cout<<place<<"\n";
        outfile<<"\n"<<company_name<<"\n";
        outfile<<place<<"\n";
        //changeColor(7);
        cout<<position<<"\t\t\t\t"<<tenure;
        outfile<<position<<"\t\t\t\t"<<tenure;
        int i=0;
        while(i<int(work_info.size()))
        {
            cout<<"\n"<<work_info.at(i);
            outfile<<"\n"<<work_info.at(i);
            i++;

        }
        cout<<"\n";
        outfile<<"\n";

    }
};

class additional_info
{
    public:
    vector<string> technical_skills;
    vector<string> languages;
    vector<string> certificate_trainings;
    vector<string> awards;

    void print_add_info(ofstream& outfile)
    {

        //changeColor(6);
        cout<<"\n"<<"Technical skills :";
        outfile<<"\n"<<"Technical skills :";
        //changeColor(7);
        int i=0;
        while(i<int(technical_skills.size()))
        {
            cout<<technical_skills.at(i)<<", ";
            outfile<<technical_skills.at(i)<<", ";
            i++;

        }
        //changeColor(6);
        cout<<"\n"<<"Languages :";
        outfile<<"\n"<<"Languages :";
        //changeColor(7);
        int j=0;
        while(j<int(languages.size()))
        {
            cout<<languages.at(j)<<", ";
            outfile<<languages.at(j)<<", ";
            j++;

        }
        //changeColor(6);
        cout<<"\n"<<"Certificates:";
        outfile<<"\n"<<"Certificates:";
        //changeColor(7);
        j=0;
        while(j<int(certificate_trainings.size()))
        {
            cout<<certificate_trainings.at(j)<<", ";
            outfile<<certificate_trainings.at(j)<<", ";
            j++;

        }
        //changeColor(6);
        cout<<"\n"<<"Awards :";
        outfile<<"\n"<<"Awards :";
        //changeColor(7);
        j=0;
        while(j<int(awards.size()))
        {
            cout<<awards.at(j)<<", ";
            outfile<<awards.at(j)<<", ";
            j++;

        }

    }


};


class projects
{
    public:
    string project_name;
    vector<string> project_info;
    string completion_year;

    void print_proj(ofstream& outfile)
    {

        //changeColor(6);
        cout<<"\n"<<project_name<<"\n";
        cout<<"Completion year : "<<completion_year;
        
        outfile<<"\n"<<project_name<<"\n";
        outfile<<"Completion year : "<<completion_year;
        //changeColor(7);
        int i=0;
        while(i<int(project_info.size()))
        {
            cout<<"\n"<<project_info.at(i);
            outfile<<"\n"<<project_info.at(i);
            i++;

        }
        cout<<"\n";
        outfile<<"\n";

    }
};


class resume
{
public:
    string first_name;
    string last_name;
    string email;
    long long mob;
    string address;
    string linkedin;

public:
    resume()
    {
        first_name="First Last";
        email="NameLast@email.com";
        mob = 2355443457;
        address = "City State Country";
        linkedin = "linked.com/in/username";



    }
};

void default_value_of_resume(education edu[2],expirence exp[2],projects proj[2],additional_info A_info)
{

        edu[0].school_name = "SCHOOL NAME ";
        edu[0].degree_name = "Bachelor of Engineering ";
        edu[0].other_info.push_back("Other information like specialization") ;
        edu[0].other_info.push_back("CGPA or percentage");
        edu[0].completion_year = " May 2022";
        edu[0].place = "Pune India";

        edu[1].school_name = "2nd SCHOOL NAME ";
        edu[1].degree_name = "Bachelor of Engineering ";
        edu[1].other_info.push_back("Other information like specialization") ;
        edu[1].other_info.push_back("CGPA or percentage");
        edu[1].completion_year = " May 2018";
        edu[1].place = "Nashik India";


        exp[0].company_name = "Company Name";
        exp[0].position = "Position in the company";
        exp[0].work_info.push_back("Work info like the work that you handled");
        exp[0].work_info.push_back("Additional information");
        exp[0].tenure = "May 2015 - Feb 2020";
        exp[0].place = "Pune India";


        proj[0].project_name = "Project name";
        proj[0].project_info.push_back("Project description");
        proj[0].project_info.push_back("Additional information about project");
        proj[0].completion_year = "March 2018";


        A_info.technical_skills.push_back("Advanced in SQL");
        A_info.technical_skills.push_back("PHP");
        A_info.technical_skills.push_back("C++");
        A_info.technical_skills.push_back("Python");
        A_info.technical_skills.push_back("Java");
        A_info.technical_skills.push_back("Android");
        A_info.technical_skills.push_back("HTML");
        A_info.technical_skills.push_back("Javascript");
        A_info.languages.push_back("English");
        A_info.languages.push_back("Hindi");
        A_info.languages.push_back("Marathi");
        A_info.languages.push_back("Gujarati");
        A_info.certificate_trainings.push_back("Python Data Structure");
        A_info.certificate_trainings.push_back("Java skills");
        A_info.certificate_trainings.push_back("Problem solving");
        A_info.awards.push_back("1st in campus in FE");
        A_info.awards.push_back("2nd in SE");

}

void print_resume_basic(resume r, ofstream& outfile)
{
    //changeColor(3);
    cout<<"\n\n\t\t\t\t RESUME";
    outfile<<"\n\n\t\t\t\t RESUME";
    //changeColor(6);
    cout<<"\nName     : ";
    outfile<<"\nName     : ";
    //changeColor(7);
    cout<<r.first_name<<" "<<r.last_name<<"\n";
	outfile<<r.first_name<<" "<<r.last_name<<"\n";
    //changeColor(6);
    cout<<"Address  : ";
    outfile<<"Address  : ";
    //changeColor(7);
    cout<<r.address<<"\n";
    outfile<<r.address<<"\n";

    //changeColor(6);
    cout<<"Mobile   : ";
    outfile<<"Mobile   : ";
    //changeColor(7);
    cout<<r.mob<<"\n";
    outfile<<r.mob<<"\n";
    //changeColor(6);
    cout<<"Email    : ";
	outfile<<"Email    : ";
    //changeColor(7);
    cout<<r.email<<"\n";
	outfile<<r.email<<"\n";
    //changeColor(6);
    cout<<"Linkedin : ";
    outfile<<"Linkedin : ";
    //changeColor(7);
    cout<<r.linkedin<<"\n";
    outfile<<r.linkedin<<"\n";

    //changeColor(7);

}

void print_education(ofstream& outfile)
{

    //changeColor(3);
    cout<<"\n\n"<<"EDUCATION  :- "<<"_______________________________________________________";
    cout<<"\n";
    outfile<<"\n\n"<<"EDUCATION  :- "<<"_______________________________________________________";
    outfile<<"\n";
    //changeColor(6);


}

void print_expirence(ofstream& outfile)
{
    //changeColor(3);
    cout<<"\n\n"<<"EXPIRENCE  :- "<<"_______________________________________________________";
    cout<<"\n";
    outfile<<"\n\n"<<"EXPIRENCE  :- "<<"_______________________________________________________";
    outfile<<"\n";
    //changeColor(6);
}

void print_projects(ofstream& outfile)
{
    //changeColor(3);
    cout<<"\n\n"<<"PROJECTS  :- "<<"_________________________________________________________";
    cout<<"\n";
    outfile<<"\n\n"<<"PROJECTS  :- "<<"_________________________________________________________";
    outfile<<"\n";
    //changeColor(6);
}

void print_additional_info(ofstream& outfile)
{
    //changeColor(3);
    cout<<"\n\n"<<"ADDITIONAL INFORMATION  :- "<<"___________________________________________";
    cout<<"\n";
    outfile<<"\n\n"<<"ADDITIONAL INFORMATION  :- "<<"___________________________________________";
    outfile<<"\n";
    //changeColor(6);
}

void print_default_resume_template()
{
	ofstream outfile(id_,ios::app);
    resume resume_creation = resume();
    education edu[5];
    expirence exp[5];
    projects proj[5];
    additional_info A_info;



    default_value_of_resume(edu,exp,proj,A_info);
    print_resume_basic(resume_creation,outfile);
    print_education(outfile);
    edu[0].print_edu(outfile);
    edu[1].print_edu(outfile);
    print_expirence(outfile);
    exp[0].print_exp(outfile);
    print_projects(outfile);
    proj[0].print_proj(outfile);
    print_additional_info(outfile);

    A_info.print_add_info(outfile);
    cout<<"\n\n";
}
resume get_basic_info(resume resume_create)
{
    cout<<"\nEnter Basic Information :-";
    cout<<"\nFirst Name = ";
    cin>>resume_create.first_name;
    cout<<"Last Name = ";
    cin>>resume_create.last_name;
    cout<<"Email = ";
    cin>>resume_create.email;
    bool r = check_email(resume_create.email);
    while(true)
    {
        if(r==false)
        {
            cout<<"YOU Enter wrong Email. Please Enter Correct Mobile number which contains 10 digits";
            cout<<"\nEmail = ";
            cin>>resume_create.email;
            r = check_email(resume_create.email);
        }
        if(r==true)
            break;
    }
    cout<<"Mobile number = ";
    cin>>resume_create.mob;
    r = check_mob(resume_create.mob);
    while(TRUE)
    {
        if(r == false)
        {
            cout<<"YOU Enter wrong Mobile no. Please Enter Correct Mobile number which contains 10 digits";
            cout<<"\nMobile number = ";
            cin>>resume_create.mob;
            r = check_mob(resume_create.mob);
        }
        if(r==true)
            break;

    }
    cout<<"Address as city name = ";
    cin.ignore();
    getline(cin,resume_create.address);
    cout<<"LinkedIn = ";
    cin>>resume_create.linkedin;
    return resume_create;
}

education get_education(education get_edu)
{
    string str;
    cout<<"\n Enter Education Details one by one:-";

        cout<<"\nEnter school name = ";
        cin.ignore();
        getline(cin,get_edu.school_name);
        cout<<"Enter Degree = ";
        getline(cin,get_edu.degree_name);
        cout<<"Enter Completion year = ";
        getline(cin,get_edu.completion_year);
        cout<<"Enter Place = ";
        getline(cin,get_edu.place);
        char choice;
        cout<<"Do you want to enter Other information about education like Specialization CGPA ? (y/n) = ";
        cin>>choice;
        while(choice == 'y' || choice == 'Y')
        {

            cout<<"Enter additional info = ";
            cin.ignore();
            getline(cin,str);
            get_edu.other_info.push_back(str);
            cout<<"Do you want to add more additional information about education ? (y/n) = ";
            cin>>choice;

        }
        return get_edu;

}

expirence get_expirence(expirence get_exp)
{


    string str;
    cout<<"\n Enter Previous Experience Details one by one:-";

        cout<<"\nEnter company name = ";
        cin.ignore();
        getline(cin,get_exp.company_name);
        cout<<"Enter Position = ";
        getline(cin,get_exp.position);
        cout<<"Enter job Tenure = ";
        getline(cin,get_exp.tenure);
        cout<<"Enter Place = ";
        getline(cin,get_exp.place);
        char choice;
        cout<<"Do you want to enter Other information about experience  like What was your role your achievements ? (y/n) = ";
        cin>>choice;
        while(choice == 'y' || choice == 'Y')
        {

            cout<<"Enter additional info = ";
            cin.ignore();
            getline(cin,str);
            get_exp.work_info.push_back(str);
            cout<<"Do you want to add more additional information about this job ? (y/n) = ";
            cin>>choice;

        }
        return get_exp;

}

projects get_project(projects get_proj)
{
    string str;
    cout<<"\n Enter Projects Details one by one:-";

        cout<<"\nEnter Project name = ";
        cin.ignore();
        getline(cin,get_proj.project_name);
        cout<<"Enter completion Year = ";
        getline(cin,get_proj.completion_year);
        char choice;
        cout<<"Do you want to enter Other information about Projects  like What was your project, Which language you used ? (y/n) = ";
        cin>>choice;
        while(choice == 'y' || choice == 'Y')
        {

            cout<<"Enter additional info = ";
            cin.ignore();
            getline(cin,str);
            get_proj.project_info.push_back(str);
            cout<<"Do you want to add more additional information about this project ? (y/n) = ";
            cin>>choice;

        }
        return get_proj;

}

additional_info get_additional_info(additional_info get_a_info)
{
    string str;
    char choice;
    cout<<"\n"<<"Enter Additional Information";
    cout<<"\nEnter Technical Skills : \n";
    do
    {
        cout<<"Enter Technical skill = ";
        cin.ignore();
        getline(cin,str);
        get_a_info.technical_skills.push_back(str);
        cout<<"Do you Want to add more Technical Skills ? (y/n) = ";
        cin>>choice;
    }while(choice =='y' || choice =='Y');


    cout<<"\nEnter Languages you know : \n";
    do
    {
        cout<<"Enter Language = ";
        cin.ignore();
        getline(cin,str);
        get_a_info.languages.push_back(str);
        cout<<"Do you Want to add more language ? (y/n) = ";
        cin>>choice;
    }while(choice =='y' || choice =='Y');


    cout<<"\nEnter certificates and Trainings : \n";
    do
    {
        cout<<"Enter certificates = ";
        cin.ignore();
        getline(cin,str);
        get_a_info.certificate_trainings.push_back(str);
        cout<<"Do you Want to add more certificates or trainings ? (y/n) = ";
        cin>>choice;
    }while(choice =='y' || choice =='Y');

    cout<<"\n"<<"Do you want add your awards earned in resume ? (y/n) = ";
    cin>>choice;
    while(choice =='y' || choice =='Y')
    {
        cout<<"Enter Awards = ";
        cin.ignore();
        getline(cin,str);
        get_a_info.awards.push_back(str);
        cout<<"Do you Want to add more Awards ? (y/n) = ";
        cin>>choice;
    }
    return get_a_info;

}
void create_user_resume()
{	
	
	//ofstream outfile("file2.txt",ios::app);
    cout<<"\n Your Resume will be created shortly";
    cout<<"\n Enter the information that is asked to you correctly to get more efficient Resume";
    cout<<"\n\nEnter your id:";
    cin>>id;
    id_=id+".txt";
	ofstream outfile(id_,ios::app);
    resume resume_create;
    resume_create = get_basic_info(resume_create);


    int edu=0;
    char choice;
    education get_edu[5];
    do
    {

        get_edu[edu] = get_education(get_edu[edu]);
        cout<<"Do you want to add one more Education details ? (y/n) = ";
        cin>>choice;
        edu++;
    }while(choice == 'y' || choice =='Y');
    //Entering Experience Details
    expirence get_exp[5];
    cout<<"\n"<<"Do you want to add Previous job or Experience Details? (y/n) = ";
    cin>>choice;
    int exp=0;
    while(choice=='y' || choice=='Y')
    {
        get_exp[exp] = get_expirence(get_exp[exp]);
        cout<<"Do you want to add one more Previous job or Experience Details? (y/n) = ";
        cin>>choice;
        exp++;
    }
    //Entering Project Details
    projects get_proj[10];
    cout<<"\n"<<"Do you want to add Projects Details? (y/n) = ";
    cin>>choice;
    int proj=0;
    while(choice=='y' || choice=='Y')
    {
        get_proj[proj] = get_project(get_proj[proj]);
        cout<<"Do you want to add one more project Details? (y/n) = ";
        cin>>choice;
        proj++;
    }
    //Entering Additional info
    additional_info get_a_info;
    get_a_info = get_additional_info(get_a_info);


    print_resume_basic(resume_create,outfile);
    print_education(outfile);
    int n=0;
    while(n<edu)
    {

        get_edu[n].print_edu(outfile);
        n++;
    }
    n=0;
    print_expirence(outfile);
    while(n<exp)
    {
        get_exp[n].print_exp(outfile);
        n++;
    }
    n=0;
    print_projects(outfile);
    while(n<proj)
    {
        get_proj[n].print_proj(outfile);
        n++;
    }
    print_additional_info(outfile);
    get_a_info.print_add_info(outfile);


}
void menu()
{
    char choice;
    
        cout<<"\nEnter your Choice from Following menu :-\n";
        cout<<"Enter N to create new Resume\n";
        cout<<"Enter D to see Default Resume Template\n";
        cout<<"Enter Q to Quite the program\n";
        cout<<"Your Choice :- ";
        cin>>choice;

        switch(choice)
        {
        case 'N':
            {
                create_user_resume();
                break;
            }
        case 'D':
            {
                print_default_resume_template();
                break;
            }
        case 'Q':
            cout<<"\nQuiting the program\nThankyou For visiting Resume Creation World\n\n";
            break;
        default:
            cout<<"\nYou Enter invalid choice...Try again !!!\n\n";
        }
    

}

int main()
{
    cout<<"******Welcome To Resume Creation World******"<<"\n";
    cout<<"\nThis site provides a free Resume creation in which \nthe user can create their own resume just by giving \ninputs of the information and"
            " your Resume is created\nin just a bit of time";
    cout<<"\n\nFeel Free to create your Resume extremely Free and Enjoy your Resume";
    cout<<"\n\nResume is the first impression of the person infront of the professional HR";
    cout<<"\nSo our Resume must be a quite impressive";
    cout<<"You can achieve this by using our service and have a impressive Resume\n\n";

    menu();

    return 0;

}






/*
0 = black
1 = blue
2 = green
3 = sky blue
4 = red
5 = pink
6 = yellow
7 = white
8 = grey
*/
