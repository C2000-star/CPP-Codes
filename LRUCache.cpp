#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node
{
    Node *next;
    Node *prev;
    int value;
    int key;
    Node(Node *p, Node *n, int k, int val) : prev(p), next(n), key(k), value(val){};
    Node(int k, int val) : prev(NULL), next(NULL), key(k), value(val){};
};

class Cache
{

protected:
    map<int, Node *> mp;            //map the key to the node in the linked list
    int cp;                         //capacity
    Node *tail;                     // double linked list tail pointer
    Node *head;                     // double linked list head pointer
    virtual void set(int, int) = 0; //set function
    virtual int get(int) = 0;       //get function
};
class LRUCache : public Cache
{
private:
    void setHelper(Node *node, int value)
    {
        if (node->prev == NULL)
        {
            node->value = value;
        }
        else if (node->next == NULL)
        {
            node->value = value;
            node->prev->next = NULL;
            node->prev = NULL;
            node->next = head;
            head = node;
        }
        else
        {
            node->value = value;
            node->prev->next = node->next;
            node->next->prev = node->prev;
            node->prev = NULL;
            node->next = head;
            head->prev = node;
            head = node;
        }
    }

public:
    LRUCache(int capacity)
    {
        cp = capacity;
    }
    void set(int key, int value)
    {
        auto findIt = mp.find(key);
        if (findIt == mp.end())
        {
            if (mp.size() == cp)
            {
                tail = tail->prev;
                mp.erase(tail->next->key);
                delete tail->next;
                tail->next = NULL;
                set(key, value);
            }
            else
            {
                if (mp.size() == 0)
                {
                    mp[key] = new Node(key, value);
                    head = mp[key];
                    tail = mp[key];
                }
                else
                {
                    mp[key] = new Node(key, value);
                    head->prev = mp[key];
                    mp[key]->next = head;
                    head = mp[key];
                }
            }
        }
        else
        {
            setHelper(mp[key], value);
        }
    }
    int get(int key)
    {
        auto findIt = mp.find(key);
        if (findIt == mp.end())
        {
            return -1;
        }
        else
        {
            setHelper(mp[key], mp[key]->value);
            return mp[key]->value;
        }
    }
};
int main()
{
    int n, capacity, i;
    cin >> n >> capacity;
    LRUCache l(capacity);
    for (i = 0; i < n; i++)
    {
        string command;
        cin >> command;
        if (command == "get")
        {
            int key;
            cin >> key;
            cout << l.get(key) << endl;
        }
        else if (command == "set")
        {
            int key, value;
            cin >> key >> value;
            l.set(key, value);
        }
    }
    return 0;
}
