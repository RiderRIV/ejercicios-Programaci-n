#include <iostream>
#include <iomanip>
using namespace std;
const int MAX=20;
// 1-25: VECTORES. Todos los recorridos son recursivos.
void e01(int v[],int n,int i=0){if(i==n)return;cin>>v[i];e01(v,n,i+1);}
void e02(const int v[],int n,int i=0){if(i==n)return;cout<<v[i]<<" ";e02(v,n,i+1);}
void e03(const int v[],int i){if(i<0)return;cout<<v[i]<<" ";e03(v,i-1);}
int e04(const int v[],int n,int i=0){if(i==n)return 0;return v[i]+e04(v,n,i+1);}
int e05(const int v[],int n,int i=0){if(i==n)return 0;return (v[i]%2==0)+e05(v,n,i+1);}
void e06(const int v[],int n,int &p,int &neg,int &c,int i=0){if(i==n)return;if(v[i]>0)p++;else if(v[i]<0)neg++;else c++;e06(v,n,p,neg,c,i+1);}
double e07(const int v[],int n){if(n<=0)return 0;return double(e04(v,n))/n;}
int e08(const int v[],int n,int k,int i=0){if(i==n)return 0;return (k!=0 && v[i]%k==0)+e08(v,n,k,i+1);}
int e09(const int v[],int n,int i=0){if(i==n-1)return v[i];int m=e09(v,n,i+1);return v[i]>m?v[i]:m;}
void e10(const int v[],int n,int &men,int &pos,int i=0){if(i==n)return;if(i==0||v[i]<men){men=v[i];pos=i;}e10(v,n,men,pos,i+1);}
int e11(const int v[],int n,int x,int i=0){if(i==n)return -1;if(v[i]==x)return i;return e11(v,n,x,i+1);}
int e12(const int v[],int n,int x,int i=0){if(i==n)return 0;return (v[i]==x)+e12(v,n,x,i+1);}
void e13(int v[],int n,int x,int y,int i=0){if(i==n)return;if(v[i]==x)v[i]=y;e13(v,n,x,y,i+1);}
void e14(int v[],int a,int b){if(a>=b)return;int t=v[a];v[a]=v[b];v[b]=t;e14(v,a+1,b-1);}
bool e15(const int v[],int n,int i=0){if(i>=n-1)return true;if(v[i]>v[i+1])return false;return e15(v,n,i+1);}
void e16(const int v[],int n,int &par,int &impar,int i=0){if(i==n)return;if(i%2==0)par+=v[i];else impar+=v[i];e16(v,n,par,impar,i+1);}
void desplazar(int v[],int n,int i){if(i>=n-1)return;v[i]=v[i+1];desplazar(v,n,i+1);}
void e17(int v[],int &n,int p){if(p<0||p>=n)return;desplazar(v,n,p);n--;}
int indiceMin(const int v[],int n,int i,int pos){if(i==n)return pos;if(v[i]<v[pos])pos=i;return indiceMin(v,n,i+1,pos);}
void e18(int v[],int n,int i=0){if(i>=n-1)return;int p=indiceMin(v,n,i+1,i);int t=v[i];v[i]=v[p];v[p]=t;e18(v,n,i+1);}
int e19(const int v[],int iz,int de,int x){if(iz>de)return -1;int m=(iz+de)/2;if(v[m]==x)return m;if(x<v[m])return e19(v,iz,m-1,x);return e19(v,m+1,de,x);}
void e20(int v[],int &n,int i=0,int j=1){if(i>=n)return;if(j>=n){e20(v,n,i+1,i+2);return;}if(v[i]==v[j]){desplazar(v,n,j);n--;e20(v,n,i,j);}else e20(v,n,i,j+1);}
void e21(int v[],int a,int b){if(a>=b)return;if(v[a]%2==0){e21(v,a+1,b);return;}if(v[b]%2!=0){e21(v,a,b-1);return;}int t=v[a];v[a]=v[b];v[b]=t;e21(v,a+1,b-1);}
void rotarUna(int v[],int i,int ultimo){if(i==0){v[0]=ultimo;return;}v[i]=v[i-1];rotarUna(v,i-1,ultimo);}
void e22(int v[],int n,int k){if(n<=0)return;k%=n;if(k==0)return;int ultimo=v[n-1];rotarUna(v,n-1,ultimo);e22(v,n,k-1);}
void e23aux(const int v[],int n,int i,int actual,int &mejor){if(actual>mejor)mejor=actual;if(i==n)return;if(v[i]>v[i-1])actual++;else actual=1;e23aux(v,n,i+1,actual,mejor);}
int e23(const int v[],int n){if(n==0)return 0;int mejor=1;e23aux(v,n,1,1,mejor);return mejor;}
void e24aux(const int v[],int n,int mayor,int &seg,bool &existe,int i=0){if(i==n)return;if(v[i]<mayor&&(!existe||v[i]>seg)){seg=v[i];existe=true;}e24aux(v,n,mayor,seg,existe,i+1);}
void e24(const int v[],int n,int &mayor,int &seg,bool &existe){mayor=e09(v,n);existe=false;e24aux(v,n,mayor,seg,existe);}
void e25aux(const int v[],int n,int i,int actual,int &mejor){if(i==n)return;if(i==0||actual<0)actual=v[i];else actual+=v[i];if(i==0||actual>mejor)mejor=actual;e25aux(v,n,i+1,actual,mejor);}
int e25(const int v[],int n){int mejor=v[0];e25aux(v,n,0,0,mejor);return mejor;}
// 26-50: MATRICES. MAX es la capacidad de columnas de los arrays tradicionales.
void e26(int m[][MAX],int f,int c,int i=0,int j=0){if(i==f)return;if(j==c){e26(m,f,c,i+1,0);return;}cin>>m[i][j];e26(m,f,c,i,j+1);}
void e27(const int m[][MAX],int f,int c,int i=0,int j=0){if(i==f)return;if(j==c){cout<<'\n';e27(m,f,c,i+1,0);return;}cout<<m[i][j]<<" ";e27(m,f,c,i,j+1);}
int e28(const int m[][MAX],int f,int c,int i=0,int j=0){if(i==f)return 0;if(j==c)return e28(m,f,c,i+1,0);return m[i][j]+e28(m,f,c,i,j+1);}
void e29(const int m[][MAX],int f,int c,int &p,int &im,int i=0,int j=0){if(i==f)return;if(j==c){e29(m,f,c,p,im,i+1,0);return;}if(m[i][j]%2==0)p++;else im++;e29(m,f,c,p,im,i,j+1);}
int e30(const int m[][MAX],int f,int c,int i=0,int j=0){if(i==f)return m[0][0];if(j==c)return e30(m,f,c,i+1,0);int resto=e30(m,f,c,i,j+1);return m[i][j]>resto?m[i][j]:resto;}
void e31(const int m[][MAX],int f,int c,int &men,int &fi,int &co,int i=0,int j=0){if(i==f)return;if(j==c){e31(m,f,c,men,fi,co,i+1,0);return;}if((i==0&&j==0)||m[i][j]<men){men=m[i][j];fi=i;co=j;}e31(m,f,c,men,fi,co,i,j+1);}
void e32(const int m[][MAX],int f,int c,int &p,int &neg,int &cer,int i=0,int j=0){if(i==f)return;if(j==c){e32(m,f,c,p,neg,cer,i+1,0);return;}if(m[i][j]>0)p++;else if(m[i][j]<0)neg++;else cer++;e32(m,f,c,p,neg,cer,i,j+1);}
void e33(const int m[][MAX],int f,int c,int x,int &fi,int &co,int i=0,int j=0){if(i==f||fi!=-1)return;if(j==c){e33(m,f,c,x,fi,co,i+1,0);return;}if(m[i][j]==x){fi=i;co=j;return;}e33(m,f,c,x,fi,co,i,j+1);}
int sumaFila(const int m[][MAX],int c,int i,int j=0){if(j==c)return 0;return m[i][j]+sumaFila(m,c,i,j+1);}
void e34(const int m[][MAX],int f,int c,int i=0){if(i==f)return;cout<<"Fila "<<i<<": "<<sumaFila(m,c,i)<<'\n';e34(m,f,c,i+1);}
int sumaCol(const int m[][MAX],int f,int j,int i=0){if(i==f)return 0;return m[i][j]+sumaCol(m,f,j,i+1);}
void e35(const int m[][MAX],int f,int c,int j=0){if(j==c)return;cout<<"Columna "<<j<<": "<<sumaCol(m,f,j)<<'\n';e35(m,f,c,j+1);}
int e36(const int m[][MAX],int n,int i=0){if(i==n)return 0;return m[i][i]+e36(m,n,i+1);}
int e37(const int m[][MAX],int n,int i=0){if(i==n)return 0;return m[i][n-1-i]+e37(m,n,i+1);}
void e38(const int m[][MAX],int n,int &enc,int &deb,int i=0,int j=0){if(i==n)return;if(j==n){e38(m,n,enc,deb,i+1,0);return;}if(j>i)enc+=m[i][j];else if(i>j)deb+=m[i][j];e38(m,n,enc,deb,i,j+1);}
void e39(const int m[][MAX],int f,int c,int i=0,int j=0){if(i==f)return;if(j==c){e39(m,f,c,i+1,0);return;}if(i==0||i==f-1||j==0||j==c-1)cout<<m[i][j]<<" ";e39(m,f,c,i,j+1);}
int e40(const int m[][MAX],int f,int c,int i=0,int j=0){if(i==f)return 0;if(j==c)return e40(m,f,c,i+1,0);int x=(i==0||i==f-1||j==0||j==c-1)?m[i][j]:0;return x+e40(m,f,c,i,j+1);}
void e41(const int m[][MAX],int f,int c,int j=0,int i=0){if(j==c)return;if(i==f){cout<<'\n';e41(m,f,c,j+1,0);return;}cout<<m[i][j]<<" ";e41(m,f,c,j,i+1);}
int mayorFila(const int m[][MAX],int c,int i,int j=0){if(j==c-1)return m[i][j];int x=mayorFila(m,c,i,j+1);return m[i][j]>x?m[i][j]:x;}
void e42(const int m[][MAX],int f,int c,int i=0){if(i==f)return;cout<<"Fila "<<i<<": "<<mayorFila(m,c,i)<<'\n';e42(m,f,c,i+1);}
bool e43(const int m[][MAX],int n,int i=0,int j=0){if(i==n)return true;if(j==n)return e43(m,n,i+1,0);if(m[i][j]!=m[j][i])return false;return e43(m,n,i,j+1);}
void e44(const int m[][MAX],int n,int i=0,int j=0){if(i==n)return;if(j==n){cout<<'\n';e44(m,n,i+1,0);return;}cout<<m[n-1-j][i]<<" ";e44(m,n,i,j+1);}
void tramoH(const int m[][MAX],int fila,int a,int b,int paso){if((paso>0&&a>b)||(paso<0&&a<b))return;cout<<m[fila][a]<<" ";tramoH(m,fila,a+paso,b,paso);}
void tramoV(const int m[][MAX],int col,int a,int b,int paso){if((paso>0&&a>b)||(paso<0&&a<b))return;cout<<m[a][col]<<" ";tramoV(m,col,a+paso,b,paso);}
void e45(const int m[][MAX],int arriba,int abajo,int iz,int der){if(arriba>abajo||iz>der)return;tramoH(m,arriba,iz,der,1);tramoV(m,der,arriba+1,abajo,1);if(arriba<abajo)tramoH(m,abajo,der-1,iz,-1);if(iz<der)tramoV(m,iz,abajo-1,arriba+1,-1);e45(m,arriba+1,abajo-1,iz+1,der-1);}
bool e46(const int m[][MAX],int n,int i=0,int j=0){if(i==n)return true;if(j==n)return e46(m,n,i+1,0);if(i>j&&m[i][j]!=0)return false;return e46(m,n,i,j+1);}
void e47(const int m[][MAX],int n,int &sup,int &inf,int i=0,int j=0){if(i==n)return;if(j==n){e47(m,n,sup,inf,i+1,0);return;}if(i<=j)sup+=m[i][j];if(i>=j)inf+=m[i][j];e47(m,n,sup,inf,i,j+1);}
int minimoFila(const int m[][MAX],int c,int i,int j=0){if(j==c-1)return m[i][j];int x=minimoFila(m,c,i,j+1);return m[i][j]<x?m[i][j]:x;}
int maximoCol(const int m[][MAX],int f,int j,int i=0){if(i==f-1)return m[i][j];int x=maximoCol(m,f,j,i+1);return m[i][j]>x?m[i][j]:x;}
void e48(const int m[][MAX],int f,int c,int &fi,int &co,int i=0,int j=0){if(i==f||fi!=-1)return;if(j==c){e48(m,f,c,fi,co,i+1,0);return;}if(m[i][j]==minimoFila(m,c,i)&&m[i][j]==maximoCol(m,f,j)){fi=i;co=j;return;}e48(m,f,c,fi,co,i,j+1);}
bool linea(const int m[][MAX],int f,int c,int k,int i,int j,int di,int dj,int faltan,int x){if(faltan==0)return true;if(i<0||i>=f||j<0||j>=c||m[i][j]!=x)return false;return linea(m,f,c,k,i+di,j+dj,di,dj,faltan-1,x);}
bool e49(const int m[][MAX],int f,int c,int k,int i=0,int j=0){if(k<=0)return false;if(i==f)return false;if(j==c)return e49(m,f,c,k,i+1,0);if(linea(m,f,c,k,i,j,0,1,k,m[i][j])||linea(m,f,c,k,i,j,1,0,k,m[i][j])||linea(m,f,c,k,i,j,1,1,k,m[i][j])||linea(m,f,c,k,i,j,1,-1,k,m[i][j]))return true;return e49(m,f,c,k,i,j+1);}
int e50(const int m[][MAX],int f,int c,int i=0,int j=0){if(i==f-1&&j==c-1)return m[i][j];if(i==f-1)return m[i][j]+e50(m,f,c,i,j+1);if(j==c-1)return m[i][j]+e50(m,f,c,i+1,j);int a=e50(m,f,c,i+1,j),b=e50(m,f,c,i,j+1);return m[i][j]+(a>b?a:b);}
void camino50(const int m[][MAX],int f,int c,int i=0,int j=0){cout<<m[i][j];if(i==f-1&&j==c-1)return;cout<<" -> ";if(i==f-1){camino50(m,f,c,i,j+1);return;}if(j==c-1){camino50(m,f,c,i+1,j);return;}if(e50(m,f,c,i+1,j)>=e50(m,f,c,i,j+1))camino50(m,f,c,i+1,j);else camino50(m,f,c,i,j+1);}
// Pruebas con los datos del enunciado. Para usar 1 y 26, llamar e01/e26 con arrays vacios.
int main(){
int v[MAX]={8,1,6,3,2,5},n=6;
cout<<"18. Seleccion: ";e18(v,n);e02(v,n);cout<<'\n';
int a[MAX]={4,7,4,2,7,9,2,5},na=8;e20(a,na);cout<<"20. Sin duplicados: ";e02(a,na);cout<<'\n';
int m[MAX][MAX]={{5,1,2},{4,8,3},{1,9,6}};
cout<<"50. Suma maxima: "<<e50(m,3,3)<<"; camino: ";camino50(m,3,3);cout<<'\n';
return 0;
}
