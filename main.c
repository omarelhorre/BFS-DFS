#include <stdlib.h>
#include <stdio.h>
#define MAX 20 // 20 sommets
int visiteDFS[MAX]; //mark dans le cours
int visiteBFS[MAX];
void initialiserMatrice(int A[MAX][MAX], int n) // A est la matrice d'adjacence / pq la matrice a max 
{
    for(int i = 0;i<n; i++)
    for(int j = 0; j<n ; j++) 
    A[i][j] = 0;
}
void remplirMatrice(int A[MAX][MAX], int n, int m)
{
    int u,v; // couple de deux sommets
    printf("Saisir les %d arretes (u,v) : \n",m);
    for(int i = 0; i<m ; i++)
    {
        scanf("%d %d",&u, &v);
        A[u-1][v-1] = 1; //car notre matrice a l'indice 0 mais l'utilisateur commence de 1
        A[v-1][u-1] = 1; // si on veut que le graph soit orienté ie la matrice soit symetrique
    }
}

void afficherMatrice(int A[MAX][MAX], int n){
    printf("\n La Matrice d'adjacence :\n");
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n ; j++)
        printf("%d ",A[i][j]);
        printf("\n");
    }
}

void DFS(int A[MAX][MAX], int n, int s)
{
    visiteDFS[s] = 1;
    printf("%d ",s+1);
    for(int v = 0; v<n; v++)
    {
        if(A[s][v] == 1 && !visiteDFS[v]) //si il existe dans la matrice d'adjacence mais il n'est pas encore visité
        DFS(A,n,v);
    }
}

void BFS(int A[MAX][MAX], int n, int s)
{
    int queue[MAX], front,rear;
    front = rear = 0;
    queue[rear++]= s; 
    visiteBFS[s] = 1;

    while(front<rear) //condition d'arret est l'égalité
    {
        int u = queue[front++];
        printf("%d ",u+1);
        for(int v = 0; v<n ; v++){
            if(A[u][v] == 1 && !visiteBFS[v]){
                visiteBFS[v] = 1;
                queue[rear++] = v;
            }
        }

    }

}
int main(void)
{
    int A[MAX][MAX];
    int n, m;
    printf("Nombre de sommets : ");
    scanf("%d",&n);
    printf("Nombre d'arretes : ");
    scanf("%d",&m);
    initialiserMatrice(A,n);
    remplirMatrice(A,n,m);
    afficherMatrice(A,n);

    //depth first search
    for(int i = 0; i<n ; i++)
    visiteDFS[i] = 0;
    printf("\n DFS :");
    for(int i = 0; i<n ; i++)
    {
        if(!visiteDFS[i])
        DFS(A,n,i);
    }

    //breadth first search
    for (int i = 0; i<n ;i++)
    visiteBFS[i] = 0;
    printf("\nBFS : ");
    for(int i = 0;i<n; i++)
    {
        if(!visiteBFS[i])
        BFS(A,n,i);
    }

    printf("\n");
    return 0;
} 

