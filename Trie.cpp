// C++ implementation of search and insert
#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;



class Node{
    public:
    Node *child[26];
    int flag;
};

class Trie {
private:
    Node *root;
public:
    Trie() {
        root = new Node();
    }

    Node *getNode()  // Returns new trie node (initialized to NULLs)
    {
        Node *pNode =  new Node();
        pNode->flag = false;

        for (int i = 0; i < 26; i++)
            pNode->child[i] = NULL;

        return pNode;
    }
    
    void insert(string str) {
        Node *p = root;

        for (int i = 0; i < str.length(); i++)
        {
            int index = str[i] - 'a';
            if (!p->child[index])
                p->child[index] = getNode();

            p = p->child[index];
        }

        p->flag = true;
    }
    
    bool search(string str) {
        Node *p = root;

        for (int i = 0; i < str.length(); i++)
        {
            int index = str[i]-'a';
            if (!p->child[index])
                return false;

            p = p->child[index];  //char found
        }

        return (p != NULL && p->flag);  //return true of flag true
    }
    
    bool startsWith(string str) {
        Node *p = root;

        for (int i = 0; i < str.length(); i++)
        {
            int index = str[i]-'a';
            if (!p->child[index])
                return false;

            p = p->child[index];  //char found
        }

        return true;  //return true of flag true
    }
};

int main()
{

    string keys[] = {"the", "a", "there","answer", "any", "by","bye", "their" };
    int n = 8;

    Trie *t = new Trie();
    t->insert("the");
    t->insert("a");
    t->insert("there");
    t->insert("answer");
    t->insert("any");
    t->insert("by");
    t->insert("bye");
    t->insert("their");

    // Search for different keys
    t->search("the")? cout << "Yes\n" :cout << "No\n";
    t->search("these")? cout << "Yes\n" : cout << "No\n";
    t->startsWith("ans")? cout << "Yes\n" : cout << "No\n";

    return 0;
}
