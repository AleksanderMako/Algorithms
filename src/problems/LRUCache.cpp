
struct Node
{
  int val;
  int key;
  Node* next;
  Node* prev;
    Node(int v, int k)
    {
        val = v; 
        key =k;
        next=NULL;
        prev=NULL;
    }
};
class LRUCache {
public:
     Node* head;
     Node* tail;
     int c;
    unordered_map<int,Node*>store;
    LRUCache(int capacity) {
         head=new Node(-1,-1);
         tail= new Node(-1,-1);
         head->next= tail;
        tail->prev= head;
        c=capacity;
    }
    
    int get(int key) {
        
        auto it = store.find(key);
        if (it == store.end()) return -1; 
        
        Node* n = store[key];
        deleteNode(n);
        insert(n);
        
      return n->val;
    }
    
    void put(int key, int value) {
        
        
        auto it = store.find(key);
        if (it !=store.end()) 
        {
            Node* update= store[key];
            update->val=value;
            deleteNode(update);
            insert(update);
            return;
        }
        
        if (c ==0)
        {
            auto it = store.find(tail->prev->key);
            store.erase(it);
            deleteNode(tail->prev);
            c++;
            
        }
       
        Node * newNode = new Node(value,key);
        insert(newNode);
        store[key]=newNode;
        c--;
        
    }
    void insert(Node* n)
    {
        n->next = head->next;
        head->next->prev=n;
        n->prev = head;
        head->next = n ;
    }
    void deleteNode(Node* n)
    {
        n->prev->next= n->next;
        n->next->prev = n->prev;
        n->prev=NULL;
        n->next = NULL;
        
    }
};
