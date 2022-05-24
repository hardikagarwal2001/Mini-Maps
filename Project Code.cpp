#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
#include<queue>
#include<stack>
#include<list>
#define RIGHT(n) setw(n)<<setiosflags(ios::right)
#define LEFT(n) setw(n)<<setiosflags(ios::left)
#define CLEAR fflush(stdin); getchar(); system("CLS");
#define SIZE 22
#define INF INT_MAX


using namespace std;


class Graph_Tour;

class Graph_List;

class City;

class Graph;

int stringcompare(string,string);


class Graph_Tour
{

public:

    Graph_Tour(void){};

    string source,destination;
    Graph_Tour(string st,string en):source(st),destination(en){};
};


int stringcompare(string str1,string str2)
{

    if(str1.size()!=str2.size())
        return 1;

    else
        for(int i=0; i<str1.size(); i++)
            if(str1[i]!=str2[i]&&abs(str1[i]-str2[i])!=abs('A'-'a'))
                return 1;

    return 0;
}


class City
{

public:

    int city_num,pre;
    string city_name;

    City():city_num(0),pre(-1) {};
    City(string str,int x):city_name(str),city_num(x),pre(-1) {};
    City(int x):city_num(x),pre(-1) {};
    City(City &temp):city_num(temp.city_num),pre(temp.pre) {};
};


class Graph
{

    int adj_mat[SIZE][SIZE],distance[SIZE],visited[SIZE];
    string start,finish;
    vector<City *> cityarr;

    void city_creator(void);
    int display_path(string str);
    int path_calculator(string str);

public:

    Graph()
    {
        for(int i=0; i<SIZE; i++)
            for(int j=0; j<SIZE; j++)
            {
                if(i==j)
                    adj_mat[i][j] = 0;

                else
                    adj_mat[i][j] = INF;
            }

        for(int i=0; i<SIZE; i++)
        {
            visited[i]=0;
            distance[i]=INF;
        }

        city_creator();
    }

    Graph_Tour * runMaps(void);
    void runMaps(string,string);
};

void Graph::runMaps(string st,string en)
{

    path_calculator(st);
    display_path(en);
}

Graph_Tour * Graph::runMaps(void)
{

    cout<<endl<<"There are following cities available:"<<endl;

    for(int i=0; i<SIZE; i++)
    {
        if(i%4==0)
            cout<<endl;

        cout.unsetf(ios::right);
        cout<<LEFT(20)<<cityarr[i]->city_name;
    }

    cout<<endl<<endl<<"Enter your source point ";
    string st;
    cin>>st;

    int result = path_calculator(st);

    if(!result)
    {
        cout<<endl<<"Programme Terminated due to invalid initial city";
        return NULL;
    }

    cout<<"Enter your destination point ";
    string destination;
    cin>>destination;

    result = display_path(destination);

    if(!result)
    {
        cout<<endl<<"Programme Terminated due to invalid destination city";
        return NULL;
    }

    return new Graph_Tour(string(st),string(destination));
}


void Graph::city_creator(void)
{
    //Amravati
    adj_mat[0][1]=adj_mat[1][0]=653;
    adj_mat[0][3]=adj_mat[3][0]=867;
    adj_mat[0][5]=adj_mat[5][0]=447;
    adj_mat[0][9]=adj_mat[9][0]=312;
    adj_mat[0][18]=adj_mat[18][0]=772;
    City * ptr = new City("Amravati",0);
    cityarr.push_back(ptr);


    //Bengaluru
    adj_mat[1][5]=adj_mat[5][1]=330;
    adj_mat[1][9]=adj_mat[9][1]=564;
    adj_mat[1][15]=adj_mat[15][1]=1028;
    adj_mat[1][16]=adj_mat[16][1]=615;
    adj_mat[1][21]=adj_mat[21][1]=720;
    ptr = new City("Bengaluru",1);
    cityarr.push_back(ptr);


    //Bhopal
    adj_mat[2][8]=adj_mat[8][2]=606;
    adj_mat[2][10]=adj_mat[10][2]=585;
    adj_mat[2][14]=adj_mat[14][2]=623;
    adj_mat[2][15]=adj_mat[15][3]=782;
    adj_mat[2][18]=adj_mat[18][2]=637;
    ptr = new City("Bhopal",2);
    cityarr.push_back(ptr);


    //Bhubaneswar
    adj_mat[3][12]=adj_mat[12][3]=444;
    adj_mat[3][18]=adj_mat[18][3]=576;
    adj_mat[3][19]=adj_mat[19][3]=469;
    ptr = new City("Bhubaneswar",3);
    cityarr.push_back(ptr);


    //Chandigarh
    adj_mat[4][6]=adj_mat[6][4]=169;
    adj_mat[4][7]=adj_mat[7][4]=251;
    adj_mat[4][11]=adj_mat[11][4]=375;
    adj_mat[4][20]=adj_mat[20][4]=110;
    ptr = new City("Chandigarh",4);
    cityarr.push_back(ptr);


    //Chennai
    adj_mat[5][21]=adj_mat[21][5]=839;
    ptr = new City("Chennai",5);
    cityarr.push_back(ptr);


    //Dehradun
    adj_mat[6][7]=adj_mat[7][6]=239;
    adj_mat[6][14]=adj_mat[14][6]=557;
    adj_mat[6][20]=adj_mat[20][6]=261;
    ptr = new City("Dehradun",6);
    cityarr.push_back(ptr);


    //Delhi
    adj_mat[7][10]=adj_mat[10][7]=261;
    adj_mat[7][14]=adj_mat[14][7]=518;
    adj_mat[7][20]=adj_mat[20][7]=347;
    ptr = new City("Delhi",7);
    cityarr.push_back(ptr);


    //Gandhinagar
    adj_mat[8][10]=adj_mat[10][8]=636;
    adj_mat[8][15]=adj_mat[15][8]=564;
    ptr = new City("Gandhinagar",8);
    cityarr.push_back(ptr);


    //Hyderabad
    adj_mat[9][15]=adj_mat[15][9]=708;
    adj_mat[9][18]=adj_mat[18][9]=784;
    ptr = new City("Hyderabad",9);
    cityarr.push_back(ptr);


    //Jaipur
    adj_mat[10][14]=adj_mat[14][10]=599;
    ptr = new City("Jaipur",10);
    cityarr.push_back(ptr);


    //Jammu
    adj_mat[11][13]=adj_mat[13][11]=766;
    adj_mat[11][20]=adj_mat[20][11]=450;
    ptr = new City("Jammu",11);
    cityarr.push_back(ptr);


    //Kolkata
    adj_mat[12][17]=adj_mat[17][12]=576;
    adj_mat[12][19]=adj_mat[19][12]=399;
    ptr = new City("Kolkata",12);
    cityarr.push_back(ptr);


    //Leh
    adj_mat[13][20]=adj_mat[20][13]=714;
    ptr = new City("Leh",13);
    cityarr.push_back(ptr);


    //Lucknow
    adj_mat[14][17]=adj_mat[17][14]=550;
    ptr = new City("Lucknow",14);
    cityarr.push_back(ptr);


    //Mumbai
    adj_mat[15][16]=adj_mat[16][15]=567;
    adj_mat[15][18]=adj_mat[18][15]=1137;
    ptr = new City("Mumbai",15);
    cityarr.push_back(ptr);


    //Panaji
    ptr = new City("Panaji",16);
    cityarr.push_back(ptr);


    //Patna
    adj_mat[17][19]=adj_mat[19][17]=320;
    ptr = new City("Patna",17);
    cityarr.push_back(ptr);


    //Raipur
    adj_mat[19][18]=adj_mat[18][19]=673;
    ptr = new City("Raipur",18);
    cityarr.push_back(ptr);

    //Ranchi
    ptr = new City("Ranchi",19);
    cityarr.push_back(ptr);


    //Shimla
    ptr = new City("Shimla",20);
    cityarr.push_back(ptr);


    //Thiruvananthapuram
    ptr = new City("Thiruvananthapuram",21);
    cityarr.push_back(ptr);
}


int Graph::display_path(string str)
{

    finish = str;
    stack<int> st;
    int pos(-1);

    for(int i=0; i<SIZE; i++)
        if(!stringcompare(str,cityarr[i]->city_name))
        {
            pos = cityarr[i]->city_num;
            break;
        }

    if(pos==-1)
    {
        cout<<endl<<"No such City exists";
        return 0;
    }

    cout<<endl<<"This trip will be of approximately "<<distance[pos]<<" kms";
    cout<<endl<<"Your journey will take "
    <<distance[pos]/60<<"Hrs "<<distance[pos]%60<<"Mins at 60kmph avg speed";
    cout<<endl<<"The route will be: ";

    while(pos!=-1)
    {
        st.push(pos);
        pos = cityarr[pos]->pre;
    }

    while(!st.empty())
    {
        cout<<endl<<cityarr[st.top()]->city_name<<" "<<distance[st.top()]<<" kms";
        st.pop();
    }

    return 1;
}


int Graph::path_calculator(string str)
{

    start = str;
    int pos(-1);

    for(int i=0; i<SIZE; i++)
        if(!stringcompare(str,cityarr[i]->city_name))
        {
            pos = cityarr[i]->city_num;
            break;
        }

    if(pos==-1)
    {
        cout<<endl<<"No such City exists";
        return 0;
    }

    queue<int> qu;
    qu.push(pos);
    distance[pos] = 0;
    cityarr[pos]->pre = -1;

    while(!qu.empty())
    {
        int del = qu.front();
        qu.pop();
        visited[del]=1;

        for(int i=0;i<SIZE;i++)
            if(i!=del&&!visited[i])
                if((adj_mat[del][i]!=INF)&&(distance[del]+adj_mat[del][i]<distance[i]))
                {
                    distance[i] = distance[del]+adj_mat[del][i];
                    cityarr[i]->pre = del;
                    qu.push(i);
                }
    }

    return 1;
}



class Graph_List
{

    list<Graph_Tour *> Gt;

public:

    Graph_List(void){};

    void newTour(void);
    void history(void);
};


void Graph_List::history(void)
{

    cout<<endl<<"You have made the following searches: "<<endl;

    if(Gt.empty())
        cout<<"No proper searches have been made";

    else
    {
        int counter = 1;

        for(auto it = Gt.begin();it != Gt.end();it++,counter++)
        {
            cout<<RIGHT(3)<<counter<<RIGHT(4)<<" ";
            cout.unsetf(ios::right);
            cout<<LEFT(20)<<(*it)->source<<LEFT(20)<<(*it)->destination<<endl;
        }

        cout<<endl<<"Do you wish to run a particular history?.....Press y/n ";

        char ch='y';
        fflush(stdin);
        do
        cin>>ch;
        while(ch!='y'&&ch!='Y'&&ch!='n'&&ch!='N');

        if(ch=='y'||ch=='Y')
        {
            int n;
            cout<<endl<<"Enter history number you wish to run: ";
            cin>>n;

            if(n>Gt.size())
            {
                cout<<endl<<"\nInvalid input ";
                return;
            }

            Graph G;
            auto it = Gt.begin();

            for(int i=1;i<n;i++)
                it++;

            G.runMaps((*it)->source,(*it)->destination);
        }
    }
}


void Graph_List::newTour(void)
{

    Graph G;
    Graph_Tour * res = G.runMaps();

    if(res)
    Gt.push_back(res);
}


main()
{
    cout<<RIGHT(65)<<"Welcome to Mini Maps"<<endl<<endl;

    int ch = 0;
    Graph_List G;

    while(ch!=3)
    {
        cout<<endl<<endl<<"Press 1 to continue ";
        cout<<endl<<"Press 2 to visit history ";
        cout<<endl<<"Press 3 to exit: ";

        do{
        fflush(stdin);
        cin.clear();
        cin>>ch;
        } while(cin.fail());

        switch(ch)
        {

        case 1:
            {
                G.newTour();
                CLEAR;
                break;
            }

        case 2:
            {
                G.history();
                CLEAR;
                break;
            }

        case 3:
            break;

        default:
            continue;
        }
    }

    cout<<endl<<endl<<RIGHT(60)<<"Thank You"<<endl;
}
