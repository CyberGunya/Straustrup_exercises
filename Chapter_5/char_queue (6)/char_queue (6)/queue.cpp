//
//  main.cpp
//  char_queue (6)
//
//  Created by Serhii Hlushenkov on 04.11.2022.
//

#include <iostream>

void error (const char* s)
{
    std::cerr<<"set: "<<s<<"\n";
}

struct char_node
{
    char_node* prev;
    char val;
    char_node* next;
    char_node(char x = '\0'){val=x;prev=nullptr;next=nullptr;};
};

class char_queue
{
    char_node* front;
    char_node* end;
public:
    char_queue();
    ~char_queue();
    char_node* find (char t);
    bool is_empty();
    void push_end(char t);
    void push_front(char t);
    void erase(char t);
    void erase_first();
    void erase_last();
    void print_queue();
};

char_queue::char_queue()
{
    char_node* x = new char_node();
    front=x;
    end=x;
}

char_queue::~char_queue()
{
    if(is_empty())
    {
        delete front;
    }
    else
    {
        while (front!=nullptr)
        {
            char_node* eraser=front;
            front=front->next;
            delete eraser;
        }
    }
}

bool char_queue::is_empty()
{
    return (front->val=='\0')&&(front->next==nullptr);
}

void char_queue::push_front(char t)
{
    char_node* insert = new char_node(t);
    if(is_empty())
    {
        front=insert;
        end=insert;
    }
    else
    {
        insert->next=front;
        front=insert;
    }
}

void char_queue::push_end(char t)
{
    char_node* insert = new char_node(t);
    if(is_empty())
    {
        front=insert;
        end=insert;
    }
    else
    {
        end->next=insert;
        insert->prev=end;
        end=insert;
    }
}

char_node* char_queue::find(char t)
{
    char_node* temp = front;
    while((temp->val!=t)&&(temp!=end))
    {
        temp=temp->next;
    }
    if(temp->val==t)
    {
        return temp;
    }
    else
    {
        error("No such value in the queue");
    }
    return nullptr;
}

void char_queue::erase_first()
{
    if(is_empty())
    {
        error("Nothing to delete");
    }
    else
    {
        if(front->next==nullptr)
        {
            front->val='\0';
        }
        else
        {
            char_node* eraser = front;
            front=front->next;
            delete eraser;
            front->prev=nullptr;
        }
    }
}

void char_queue::erase_last()
{
    if(is_empty())
    {
        error("Nothing to delete");
    }
    else
    {
        if(end->prev==nullptr)
        {
            end->val='\0';
        }
        else
        {
            char_node* eraser = end;
            end=end->prev;
            delete eraser;
            end->next=nullptr;
        }
    }
}

void char_queue::erase(char t)
{
    char_node* eraser = find(t);
    if(eraser==front)
    {
        erase_first();
    }
    else
    {
        if(eraser==end)
        {
            erase_last();
        }
        else
        {
            if(eraser==nullptr)
            {
                error("Such value doesn't exist in the queue");
            }
            else
            {
                eraser->prev->next=eraser->next;
                eraser->next->prev=eraser->prev;
                delete eraser;
            }
        }
    }
}

void char_queue::print_queue()
{
    char_node* temp = front;
    do {
        std::cout<<temp->val<<" ";
        temp=temp->next;
    } while (temp!=nullptr);
    std::cout<<"\n";
}


int main(int argc, const char * argv[]) {
    char_queue queue;
    queue.find('x');
    queue.push_end('x');
    queue.push_end('y');
    queue.push_end('z');
    queue.push_front('q');
    queue.print_queue();
    queue.erase_last();
    queue.print_queue();
    queue.erase_first();
    queue.erase('y');
    queue.print_queue();
    
    return 0;
}
