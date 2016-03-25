#include<iostream>
using namespace std;
typedef struct polynomial//单链表的节点类型
{
    double coef;
    int expn;
    polynomial *next;
}LNode,*LinkList;
LinkList InitList(LinkList &L)//初始化单链表   不带头结点
{
    L=NULL;
    return L;
}

void ClearList(LinkList L)//清空单链表
{
    L->next=NULL;
}

void DestroyList(LinkList &L)//销毁线性表
{
    LinkList p;
    p=L;
    while(L)
    {
      L=p->next;
      delete p;
      p=L;
    }
}

LinkList ListEmpty(LinkList L)//判断该多项式单链表是否为空 检查所有系数  若均为0 即该多项式为空
{
    LinkList p;
    int t=0;
    p=L;
    while(p)
    {
        if(p->coef==0) ;
        else t=1;
        p=p->next;
    }
    if(t==0) L=NULL;
    return L;
}

int ListLength(LinkList L) //求单链表长度  对多项式了来说 系数为0跳过
{
    LinkList p;
    int t=0;
    p=L;
    while(p)
    {
        if(p->coef!=0)
        t++;
        p=p->next;
    }
    return t;
}

LinkList Insert(LinkList h,LinkList k)//插入一个节点  按指数升序 插入
{
    LinkList p,q,temp;
    temp=h;
    q=k;
    if(h==NULL)
    {
        h=q;
        q->next=NULL;
        return h;
    }
    else
    {
        while(q->expn>temp->expn&&temp->next!=NULL)
        {
            p=temp;
            temp=temp->next;
        }

            if(q->expn<temp->expn)
            {
                if(h==temp)
                {
                    q->next=temp;
                    h=q;
                }
                else
                {
                    p->next=q;
                    q->next=temp;
                }
            }
            if(q->expn==temp->expn)
            {
                temp->coef=temp->coef+q->coef;
                delete q;
            }
        if(q->expn>temp->expn)
        {
            temp->next=q;
            q->next=NULL;
        }
    }
    return h;
}

LinkList Invert(LinkList head)//将单链表倒序排列
{
    LinkList p,q;
    if(head->next)
        p=head->next;
        head->next=NULL;
        while(p)
        {
            q=p->next;
            p->next=head;
            head=p;
            p=q;
        }
        return head;
}

int main()
{
    LinkList Pa,Pb,Pc,Pd;
    LinkList Create();//创建多项式
    LinkList Insert(LinkList,LinkList);//按指数升序插入一个节点
    void Print(LinkList);
    LinkList Add(LinkList,LinkList);//将多项式相加
    LinkList Differentiate(LinkList);

    cout<<"按要求输入多项式，当系数和指数均为0时，多项式输入结束"<<'\n';
    cout<<"请输入多项式Pa各项的系数，指数："<<endl;
    Pa=Create();
    cout<<"输出Pa多项式（按指数升序排列）：";
    Print(Pa);
    cout<<endl;
    cout<<"该多项式有"<<ListLength(Pa)<<"项"<<endl;

    cout<<"请输入多项式Pb各项的系数，指数："<<endl;
    Pb=Create();
    cout<<"输出Pb多项式（按指数升序排列）：";
    Print(Pb);
    cout<<endl;

    Pc=InitList(Pc);
    Pc=Add(Pa,Pb);
    cout<<"多项式Pa+Pb 结果按指数升序排列：";
    Print(Pc);
    cout<<endl;
//    cout<<"多项式Pa+Pb 结果按指数降序排列：";
//    Pc=daoxu(Pc);
//    print(Pc);
//    cout<<endl;

    cout<<"该多项式求导结果为："<<endl;
    Pd=Differentiate(Pc);
    Print(Pd);
    DestroyList(Pa);
    DestroyList(Pb);
    DestroyList(Pc);
    DestroyList(Pd);

}

LinkList Create()
{
    LinkList h,p;
    int i=1;
    h=InitList(h);//初始化单链表
    p=new LNode;
    cout<<"第"<<i<<"项  "<<"系数: ";
    cin>>p->coef;
    cout<<"       "<<"指数: ";
    cin>>p->expn;
    if((p->coef==0)&&(p->expn==0))
        return h;
    else
    {
        while(p->coef!=0||p->expn!=0)
        {
            h=Insert(h,p);
            p=new LNode;
            cout<<++i<<"项数"<<"  系数: ";
            cin>>p->coef;
            cout<<"       "<<"指数: ";
            cin>>p->expn;
            if((p->coef==0)&&(p->expn==0))
                break;
        }
        return h;
    }
}

void Print(LinkList h)
{
    LinkList p;
    int t=0;
    p=h;
    if(h==NULL)
    {
        cout<<"该多项式为0";
    }
    else
    {
        do
        {
            if(p->coef==0)
                p=p->next;
            if(p==NULL)
                break;
            if(p->coef!=0)
            {
                if((p->expn!=0)&&(p->expn!=1))
                {
                    if(t==0)
                    {   if(p->coef==1) {cout<<"x"<<"^"<<p->expn;}
                        else if(p->coef==-1) {cout<<"-x"<<"^"<<p->expn;}
                             else   {cout<<p->coef<<"x^"<<p->expn;}
                    }
                    else
                    {
                        if(p->coef>=0)
                        {   if(p->coef==1)  cout<<"+"<<"x"<<"^"<<p->expn;
                            else            cout<<"+"<<p->coef<<"x"<<"^"<<p->expn;
                        }
                        else
                        {   if(p->coef==-1)  cout<<"-x"<<"^"<<p->expn;
                            else            cout<<""<<p->coef<<"x"<<"^"<<p->expn;
                        }
                    }
                p=p->next;
                t=1;
                }
                else if(p->expn==0)
                {
                    if(t==0)
                    {
                        cout<<p->coef;
                    }
                    else
                    {
                        if(p->coef>=0)
                        {
                            cout<<"+"<<p->coef;
                        }
                        else
                        {
                            cout<<""<<p->coef;
                        }
                    }
                p=p->next;
                t=1;
                }
                else if(p->expn==1)
                {
                    if(t==0)
                    {   if(p->coef==1)  cout<<"x";
                        else if(p->coef==-1) cout<<"-x";
                            else  cout<<p->coef<<"x";
                    }
                    else
                    {
                        if(p->coef>=0)
                        {   if(p->coef==1) cout<<"+"<<"x";
                            else cout<<"+"<<p->coef<<"x";
                        }
                        else
                        {   if(p->coef==-1) cout<<"-"<<"x";
                            else cout<<""<<p->coef<<"x";
                        }
                    }
                p=p->next;
                t=1;
                }
            }
        }while(p);
    }
}

LinkList Add(LinkList k,LinkList h)
{
    LinkList p,q;
    //int t=0;
    while(h!=NULL)
    {
        p=new LNode;
        p->coef=h->coef;
        p->expn=h->expn;
        k=Insert(k,p);
        h=h->next;
    }
    q=k;
    k=ListEmpty(k);
//    while(q)
//    {
//        if(q->coef==0);
//        else t=1;
//        q=q->next;
//    }
//    if(t==0)
//        k=NULL;
    return k;
}

LinkList Differentiate(LinkList k)
{
    LinkList q,s;
    q=InitList(q);
    if(k==NULL)
    {
        cout<<"该多项式不能求导"<<endl;
    }
    else
    {
        while(k)
        {
            s=new LNode;
            s->coef=(k->coef)*(k->expn);
            s->expn=(k->expn)-1;
            q=Insert(q,s);
            k=k->next;
        }
    }
    return q;
}
