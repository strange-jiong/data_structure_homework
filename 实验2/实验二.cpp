#include<iostream>
using namespace std;
typedef struct polynomial//������Ľڵ�����
{
    double coef;
    int expn;
    polynomial *next;
}LNode,*LinkList;
LinkList InitList(LinkList &L)//��ʼ��������   ����ͷ���
{
    L=NULL;
    return L;
}

void ClearList(LinkList L)//��յ�����
{
    L->next=NULL;
}

void DestroyList(LinkList &L)//�������Ա�
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

LinkList ListEmpty(LinkList L)//�жϸö���ʽ�������Ƿ�Ϊ�� �������ϵ��  ����Ϊ0 ���ö���ʽΪ��
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

int ListLength(LinkList L) //��������  �Զ���ʽ����˵ ϵ��Ϊ0����
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

LinkList Insert(LinkList h,LinkList k)//����һ���ڵ�  ��ָ������ ����
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

LinkList Invert(LinkList head)//��������������
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
    LinkList Create();//��������ʽ
    LinkList Insert(LinkList,LinkList);//��ָ���������һ���ڵ�
    void Print(LinkList);
    LinkList Add(LinkList,LinkList);//������ʽ���
    LinkList Differentiate(LinkList);

    cout<<"��Ҫ���������ʽ����ϵ����ָ����Ϊ0ʱ������ʽ�������"<<'\n';
    cout<<"���������ʽPa�����ϵ����ָ����"<<endl;
    Pa=Create();
    cout<<"���Pa����ʽ����ָ���������У���";
    Print(Pa);
    cout<<endl;
    cout<<"�ö���ʽ��"<<ListLength(Pa)<<"��"<<endl;

    cout<<"���������ʽPb�����ϵ����ָ����"<<endl;
    Pb=Create();
    cout<<"���Pb����ʽ����ָ���������У���";
    Print(Pb);
    cout<<endl;

    Pc=InitList(Pc);
    Pc=Add(Pa,Pb);
    cout<<"����ʽPa+Pb �����ָ���������У�";
    Print(Pc);
    cout<<endl;
//    cout<<"����ʽPa+Pb �����ָ���������У�";
//    Pc=daoxu(Pc);
//    print(Pc);
//    cout<<endl;

    cout<<"�ö���ʽ�󵼽��Ϊ��"<<endl;
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
    h=InitList(h);//��ʼ��������
    p=new LNode;
    cout<<"��"<<i<<"��  "<<"ϵ��: ";
    cin>>p->coef;
    cout<<"       "<<"ָ��: ";
    cin>>p->expn;
    if((p->coef==0)&&(p->expn==0))
        return h;
    else
    {
        while(p->coef!=0||p->expn!=0)
        {
            h=Insert(h,p);
            p=new LNode;
            cout<<++i<<"����"<<"  ϵ��: ";
            cin>>p->coef;
            cout<<"       "<<"ָ��: ";
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
        cout<<"�ö���ʽΪ0";
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
        cout<<"�ö���ʽ������"<<endl;
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
