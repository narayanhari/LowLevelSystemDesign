#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class NotifyObserver{
    public:
        virtual void update() = 0;
};

class StockObservable{
    public:
        virtual void add( NotifyObserver* obj) =0;
        virtual void remove( NotifyObserver* obj) =0;

        virtual void notify() = 0;
        virtual void setData(int stockValue) = 0;
        virtual int getData() = 0;
};

class IphoneObservable: public StockObservable{
    public:
        void add ( NotifyObserver* observer) override{
            observer_list.push_back(observer);
        }

        void remove ( NotifyObserver* observer) override{
            observer_list.remove(observer);
        }
        void notify() override{
            for(auto obj : observer_list){
                obj->update();
            }
        }
        void setData(int stockValue) override{
            if(stock == 0){
                notify();
            }
            stock += stockValue;
        }
        int getData(){
            return stock;
        }

    private:
        list<NotifyObserver *> observer_list;
        int stock = 0;
};

class EmailOberserver : public NotifyObserver{
    public:
        EmailOberserver(string emailId, StockObservable *obj){
            this->observable = obj;
            this->emailId = emailId;
        }

        void update(){
            sendEmail(emailId,"product in stock");
        }
        void sendEmail(string emailId, string msg){
            cout<<"email sent to "<<emailId<<" with msg = "<<msg<<endl;
        }
    private:
        StockObservable* observable;
        string emailId;
};

class MobileOberserver : public NotifyObserver{
    public:
        MobileOberserver(string username, StockObservable *obj){
            this->observable = obj;
            this->username = username;
        }

        void update(){
            sendMsg(username,"product in stock");
        }
        void sendMsg(string username, string msg){
            cout<<"msg sent to "<<username<<" with msg = "<<msg<<endl;
        }
    private:
        StockObservable* observable;
        string username;
};

int main(){
    StockObservable* iphoneObservable = new IphoneObservable();

    NotifyObserver* observer1 = new MobileOberserver("x1",iphoneObservable);
    NotifyObserver* observer2 = new MobileOberserver("y1",iphoneObservable);
    NotifyObserver* observer3 = new EmailOberserver("z1@gmail.com",iphoneObservable);

    iphoneObservable->add(observer1);
    iphoneObservable->add(observer2);
    iphoneObservable->add(observer3);

    iphoneObservable->setData(10);
    iphoneObservable->setData(-10);
    iphoneObservable->setData(10);

    return 0;
}
