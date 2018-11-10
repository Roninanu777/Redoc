#include<stdio.h>
#include<malloc.h>
struct node
{
	int DATA;
        struct node *LEFT;
        struct node *RIGHT;
};
struct node *tree;
void create_tree(struct node *tree)
{
        tree=NULL;
}
void insertElement()
{
	int val;
        struct node *PTR,*nodePTR,*parentPTR;
        printf("Enter the value or press 0 to exit: ");
        scanf("%d",&val);
	while(val!=0)
	{
        PTR=(struct node*)malloc(sizeof(struct node));
        PTR->DATA=val;
        PTR->LEFT=NULL;
        PTR->RIGHT=NULL;
        if(tree==NULL)
        {
		tree=PTR;
                tree->LEFT=NULL;
                tree->RIGHT=NULL;
        }
        else
        {
                parentPTR=NULL;
                nodePTR=tree;
                while(nodePTR!=NULL)
                {
                       parentPTR=nodePTR;
                       if(val<nodePTR->DATA)
                       {
		            nodePTR=nodePTR->LEFT;
                       }
		       else
    		       {
                            nodePTR=nodePTR->RIGHT;
                       }
                }
                if(val<parentPTR->DATA)
                {
                       parentPTR->LEFT=PTR;
                }
                else
                {
                       parentPTR->RIGHT=PTR;
                }
        }
	printf("Enter the value press 0 to exit: ");
        scanf("%d",&val);
	}
}
void preorderTraversal(struct node *tree)
{
	if(tree!=NULL)
        {
                printf("%d ",tree->DATA);
                preorderTraversal(tree->LEFT);
                preorderTraversal(tree->RIGHT);
        }
}
void inorderTraversal(struct node *tree)
{
        if(tree!=NULL)
        {
                inorderTraversal(tree->LEFT);
                printf("%d ",tree->DATA);
                inorderTraversal(tree->RIGHT);
        }
}
void postorderTraversal(struct node *tree)
{
        if(tree!=NULL)
        {
                postorderTraversal(tree->LEFT);
                postorderTraversal(tree->RIGHT);
                printf("%d ",tree->DATA);
        }
}
struct node *findsmallest(struct node *tree)
{
        if((tree==NULL)||(tree->LEFT==NULL))
        {
                return tree;
        }
        else
        {
                return findsmallest(tree->LEFT);
        }
}
struct node *findlargest(struct node *tree)
{
        if((tree==NULL)||(tree->RIGHT==NULL))
        {
                return tree;
        }
        else
        {
                return findlargest(tree->RIGHT);
        }
}
struct node *searchelement(struct node *tree,int num)
{
        printf("\nEnter the number you want to search: ");
        scanf("%d",&num);
        if((tree->DATA==num)||(tree==NULL))
        {
                return tree;
        }
        else if(num<tree->DATA)
        {
                return searchelement(tree->LEFT,num);
        }
        else
        {
                return searchelement(tree->RIGHT,num);
        }
}
int height(struct node *tree)
{
        int leftheight,rightheight;
        if(tree==NULL)
        {
                return 0;
        }
        else
        {
                leftheight=height(tree->LEFT);
                rightheight=height(tree->RIGHT);
                if(leftheight>rightheight)
                {
			return (leftheight+1);
                }
                else
                {
                        return (rightheight+1);
                }
        }
}
int totalnodes(struct node *tree)
{
        if(tree==NULL)
        {
                return 0;
        }
        else
        {
                return (totalnodes(tree->LEFT)+totalnodes(tree->RIGHT)+1);
        }
}
int totalinternalnodes(struct node *tree)
{
        if(tree==NULL)
        {
                return 0;
        }
        if((tree->LEFT==NULL)&&(tree->RIGHT==NULL))
        {
                return 0;
        }
        else
        {
                return (totalinternalnodes(tree->LEFT)+totalinternalnodes(tree->RIGHT)+1);
        }
}
int totalexternalnodes(struct node *tree)
{
        if(tree==NULL)
        {
                return 0;
        }
        else if(tree->LEFT==NULL&&tree->RIGHT==NULL)
        {
                return 1;
        }
        else
        {
                return (totalexternalnodes(tree->LEFT)+totalexternalnodes(tree->RIGHT)+1);
        }
}
struct node *deleteelement(struct node *tree,int num)
{
        struct node *TEMP;
        printf("\nEnter the element to delete: ");
        scanf("%d",&num);
        if(tree==NULL)
        {
                printf("\nThe element is not in tree");
        }
        else if(num<tree->DATA)
        {
                tree->LEFT=deleteelement(tree->LEFT,num);
        }
        else if(num>tree->DATA)
        {
                tree->RIGHT=deleteelement(tree->RIGHT,num);
        }
        else if(tree->LEFT&&tree->RIGHT)
        {
                TEMP=findlargest(tree->LEFT);
                tree->DATA=TEMP->DATA;
                deleteelement(tree->LEFT,num);
        }
        else
        {
                TEMP=tree;
                if((tree->LEFT==NULL)||(tree->RIGHT==NULL))
                {
			tree==NULL;
                }
                else if(tree->LEFT!=NULL)
                {
                        tree=tree->LEFT;
                }
                else
                {
                        tree=tree->RIGHT;
                }
        }
        preorderTraversal(tree);
}
int main()
{
        int val;
        int num;
        int option;
        struct node *PTR;
        create_tree(tree);
        do
        {
	        printf("\n1.Insert new elements: ");
	        printf("\n2.Preorder traversal: ");
                printf("\n3.Inorder Traversal: ");
                printf("\n4.Postorder Traversal: ");
                printf("\n5.Find the smallest node: ");
                printf("\n6.Find the largest node: ");
                printf("\n7.Search any element: ");
                printf("\n8.Total number of nodes: ");
                printf("\n9.Total number of internal nodes: ");
                printf("\n10.Total number of external nodes: ");
                printf("\n11.Height of the tree: ");
	        printf("\n12.Delete an element: ");
                printf("\n13.EXIT");
	        printf("\nEnter your choice: ");
	        scanf("%d",&option);
	        switch(option)
	        {
			case 1:insertElement();
			       break;
		        case 2:printf("\nThe elements of the tree are: ");
		               preorderTraversal(tree);
		               break;
                        case 3:printf("\nThe elements of the tree are: ");
                               inorderTraversal(tree);
                               break;
                        case 4:printf("\nThe elements of the tree are: ");
                               postorderTraversal(tree);
                               break;
                        case 5:PTR=findsmallest(tree);
                               printf("\nThe smallest node in the tree is %d",PTR->DATA);
                               break;
                        case 6:PTR=findlargest(tree);
                               printf("\nThe largest node in the tree is %d",PTR->DATA);
                               break;
                        case 7:PTR=searchelement(tree,num);
                               printf("\nThe number is %d",PTR->DATA);
                               break;
                        case 8:printf("\nThe total number of nodes in the tree is %d",totalnodes(tree));
                               break;
                        case 9:printf("\nThe total number of internal nodes in the tree is %d",totalinternalnodes(tree));
                               break;
                        case 10:printf("\nThe total number of external nodes in the tree is %d",totalexternalnodes(tree));
                                break;
                        case 11:printf("\nThe height of the tree is %d",height(tree));
                                break;
                        case 12:tree=deleteelement(tree,num);
                                printf("\nThe element deleted is %d",tree->DATA);
                                break;
	        }  
        }
	while(option!=13);
        return 0;
}
