#include<bits/stdc++.h>
using namespace std;

class  publication
{
    private:
    string title;
    float price;

    public:
    void add()
    {
        cout<<"enter publication detail \n";
        cout<<"enter title of publication: ";
        cin.ignore();
        getline(cin,title);
        cout<<"enter price of publication: ";
        cin>>price;

    }
     
    void disp()
    {
        cout<<"\n title of publication is: "<<title;
        cout<<"\n price of publication is: "<<price;
    }
};

class book:public publication
{
    private:
    int pg_cnt;

    public:
    void add_bk()
    {
        add();
        cout<<"enter page count: ";
        cin>>pg_cnt;
        if(pg_cnt<=0)
        {
            throw pg_cnt;

        }
        
        
    }

    void disp_bk()
    {
        cout<<"\npage count is: "<<pg_cnt<<"\n";
    }
};

class tape:public publication
{
    private:
    float py_time;

    public:
    void add_tp()
    {
        add();
        cout<<"enter play time of tape in minutes: ";
        cin>>py_time;
        if(py_time<=0)
        {
            throw py_time;
        }
    }

    void disp_tp()
    {
        cout<<"\nplay time of tape is: "<<py_time<<"min"<<"\n";
    }

};

int main()
{
    book b[5];
    tape t[5];
    int cs,b_cnt=0,t_cnt=0;

    while(cs!=5)
    {
        cout<<"\nPUBLICATION DATABASE";
        cout<<"\n\nCASE 1: ADD BOOKS";
        cout<<"\nCASE 2: ADD TAPES";
        cout<<"\nCASE 3: DISPLAY BOOKS";
        cout<<"\nCASE 4: DISPLAT TAPES";
        cout<<"\nCASE 5: EXIT CODE";

        cout<<"\n\nENTER your Choice: ";
        cin>>cs;
        cout<<"\n";

        switch(cs)
        {
            case 1:
            b[b_cnt].add_bk();
            b_cnt++;
            break;

            case 2:
            t[t_cnt].add_tp();
            t_cnt++;
            break;

            case 3:
            cout<<"BOOK PUBLICATION DATABASE\n";
            for(int i=0;i<b_cnt;i++)
            {
                b[i].disp();
                b[i].disp_bk();

            }
            break;

            case 4:
            cout<<"TAPE PUBLICATION DATABASE\n";
            for(int i=0;i<t_cnt;i++)
            {
                
            }
        }
    }
}
