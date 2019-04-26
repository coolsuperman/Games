#include<iostream>
#include<vector>

using namespace std;

#define Root 2

int n,m,p;
int action[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int maze[10][10];
int cost[4] = {3,0,1,1};
int final_p = -1;

struct Mazepoint{
  Mazepoint(int x,int y)
    :_x(x)
     ,_y(y)
  {}
  int _x;
  int _y;

};

vector<Mazepoint> path;
vector<Mazepoint> best;

void Search(int x,int y,int p1){
  Mazepoint ne (x,y);
  path.push_back(ne);
  if(x==0&&y==m-1&&p1>=0){
    if(p1>final_p)
      final_p = p1;
    best = path;
    path.pop_back();
    return;

  }
  maze[x][y]= Root;
  if(p>0){
    for(int i =0;i<4;i++){
      int new_x = x+action[i][0];
      int new_y = y+action[i][1];
      int new_p = p1-cost[i];
      if(new_x<n && new_x>=0 && new_y<m && new_y>=0 && new_p>=0 && maze[new_x][new_y]==1)
        Search(new_x,new_y,new_p);

    }

  }
  path.pop_back();//因为是全局的所以用完就要扔掉；
  maze[x][y] = 1;

}

void PrintPath(){
  int size = best.size();
  for(int i = 0;i<size;i++){
    cout<<"["<<best[i]._x<<","<<best[i]._y<<"]";
    if(i!=size-1)
      cout<<",";
    else
      cout<<endl;

  }

}

int main(){
  cin>>n>>m>>p;
  for(int i = 0;i<n;i++){
    for(int j = 0;j<m;j++){
      cin>>maze[i][j];

    }

  }
  Search(0,0,p);
  if(final_p==-1)
    cout<<"Can not escape!"<<endl;
  else
    PrintPath();
  return 0;

}
