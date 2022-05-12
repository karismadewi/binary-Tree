#include <iostream>

using namespace std;

//make node
struct node
{
    int value;
    node* left;
    node* right;
    node* parent;
};
 node* root; 

//searching node
node* searchNode(int val)
{
    node* tmp = root;
    while (tmp->value != val)
    {
        if(tmp == NULL)
        {
            return NULL;
        }

        if(val>tmp->value)
        {
            tmp = tmp->right;
        }

        else if(val<tmp->value)
        {
            tmp = tmp->left;
        }
    }
    return tmp; 
}



//insert
void insert (int val)
{
    node *newNode       = new node();
    newNode -> left     = NULL;
    newNode -> right    = NULL; 
    newNode -> parent   = NULL;
    newNode -> value    = val;

    if (root == NULL)
    {
        root = newNode;
    }
    else 
    {
        node* tmp = root; 
        while (true)
        {
            
            if(val == tmp->value)
            {
                cout<<"ERROR! The value has already in the tree"<<endl;
                break;
            }
            
            else if(val > tmp->value)
            {
                if(tmp->right == NULL)
                {
                    tmp->right      = newNode; 
                    newNode->parent = tmp;
                    break;
                }
                else 
                {
                    tmp = tmp->right;
                }
            }
            else
            {
                if(tmp->left == NULL)
                {
                    tmp->left      = newNode; 
                    newNode->parent = tmp;
                    break;
                }
                else 
                {
                    tmp = tmp->left;
                }
            }

        }

    }
}

//output
void printGraph(node* root, int depth = 0)
{
    if(root != NULL)
    {
        // cout<< "test" << endl;
        printGraph (root->right, depth+1);
        for(int i=0;i<depth;i++)
        {
            cout<<"    ";
        }
        cout<<"->"<<root->value<<endl;
        printGraph(root->left, depth+1);
    }
}

//delete ------------------------------

void deleteNode(int val)
{
    node* target = searchNode(val);

    if((target->left == NULL) && (target->right == NULL))
    {
        node* tmp = target->parent;
        if(tmp->right == target)
        {
            tmp->right = NULL;
        }

        else if(tmp->left == target)
        {
            tmp->left = NULL;
        }
        delete (target);    
    
    }

    else if ((target->left == NULL) || (target->right == NULL))
    {
        if(target->right == NULL)
        {
            node* tmp = target->parent;
            if(tmp->right == target)
            {
                tmp->right = target->left;
                target->left->parent = tmp; 
            }

            else if(tmp->left == target)
            {
                tmp->left = target->left;
                target->left->parent = tmp; 
            }
            delete (target);
        }

        else if(target->left == NULL)
        {
            node* tmp = target->parent;
            if(tmp->right == target)
            {
                tmp->right = target->right;
                target->right->parent = tmp; 
            }

            else if(tmp->left == target)
            {
                tmp->left = target->right;
                target->right->parent = tmp; 
            }
            delete (target);
        }

    }
    else
    {
        //cari node pengganti
        node* replacer = target->right;
        while (replacer->left != NULL)
        {
            replacer = replacer->left;
        }
        // cout<< replacer->value;

        //ganti replacer dangan node kanan
        if (replacer->right != NULL)
        {
            if(replacer->parent->left == replacer)
            {
                replacer->parent->left= replacer->right;
            }
            else if(replacer->parent->right == replacer)
            {
                replacer->parent->right=  replacer->right;
            }
        }
        else{
            
            if(replacer->parent->left == replacer)
            {
                replacer->parent->left= NULL;
            }
            else if(replacer->parent->right == replacer)
            {
                replacer->parent->right=  NULL;
            }
        }

        // cout<< "test";

        node* tParent = target->parent;
        // cout<< tParent->value;
        if(tParent->left == target )
        {
            tParent->left = replacer;
            replacer->left = target->left;
            replacer->right = target->right;
            replacer->parent = tParent;

        }
        else if(tParent->right == target )
        {
            tParent->right = replacer;
            replacer->left = target->left;
            replacer->right = target->right;
            replacer->parent = tParent;
        }

        delete(target);


        

//kalau node nya dua anak
    }



}



int main()
{

insert(4);
insert(1);
insert(5);
insert(2);
insert(3);
insert(9);
insert(6);
insert(10);

printGraph(root);

cout<<"-----------------------\n"<<endl;
// deleteNode();
// cout<<"test\n"<<endl;
printGraph(root);

 return 0;
}


