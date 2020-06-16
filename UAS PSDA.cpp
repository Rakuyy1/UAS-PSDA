//header file
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

//pendeklarasian struct sebuah tree awal
struct Node{
      int data;
      Node *kiri;
      Node *kanan;
};

Node *pohon = NULL;

//fungsi untuk menambahkan node baru
void tambah(Node **root, int databaru)
{
      //jika root masih kosong
      if((*root) == NULL)
      {
            //pembuatan node baru
            Node *baru;
            //pengalokasian memori dari node yang telah dibuat
            baru = new Node;
            //inisialisasi awal node yang baru dibuat
            baru->data = databaru;
            baru->kiri = NULL;
            baru->kanan = NULL;
            (*root) = baru;
            (*root)->kiri = NULL;
            (*root)->kanan = NULL;
            printf("Data bertambah!");
      }
     //jika data yang akan dimasukkan lebih kecil daripada elemen root, maka akan diletakkan di node sebelah kiri.
      else if(databaru<(*root)->data)
            tambah(&(*root)->kiri, databaru);
     //jika data yang akan dimasukkan lebih besar daripada elemen root, maka akan diletakkan di node sebelah kanan
      else if(databaru>(*root)->data)
            tambah(&(*root)->kanan, databaru);
     //jika saat dicek data yang akan dimasukkan memiliki nilai yang sama dengan data pada root
      else if(databaru == (*root)->data)
            printf("Data sudah ada!");
}

//fungsi yang digunakan untuk mencetak tree secara preOrder
void preOrder(Node *root)
{
      if(root != NULL){
            printf("%d ", root->data);
            preOrder(root->kiri);
            preOrder(root->kanan);
      }
}

//fungsi yang digunakan untuk mencetak tree secara inOrder
void inOrder(Node *root)
{
      if(root != NULL){
            inOrder(root->kiri);
            printf("%d ", root->data);
            inOrder(root->kanan);
      }
}

//fungsi yang digunakan untuk mencetak tree secara postOrder
void postOrder(Node *root)
{
      if(root != NULL){
            postOrder(root->kiri);
            postOrder(root->kanan);
            printf("%d ", root->data);
      }
}

int count(Node *root){
	if(root == NULL)
	return 0;
	return count(root->kiri) + count(root->kanan) +1;
}

void search(Node **root, int cari){
	if((*root) == NULL){
		printf("Tidak ditemukan!");
	}
	else if(cari < (*root)->data)
		search(&(*root)->kiri,cari);
	else if(cari < (*root)->data)
		search(&(*root)->kanan,cari);
	else if(cari == (*root)->data)
		printf("Ditemukan!");
}

int height(Node *root)
{
       if(root == NULL)
              return -1;
       else{
              int u = height(root->kiri);
        int v = height(root->kanan);
        if(u > v)
          return u + 1;
        else
          return v + 1;
       }
}


void hapus(Node **root, int del)
{
       Node *curr;
       Node *parent;
       curr = (*root);

       bool flag = false;
  
       while(curr != NULL)
       {
              if(curr->data == del)
              {
                     flag = true;
                      break;
                      
              }
              else
              {
                  parent = curr;
                  if(del>curr->data)
                     curr = curr->kanan;
                  else
                     curr = curr->kiri;
              }
       }

    if(!flag)
    {
        cout<<"Data tidak ditemukan. Penghapusan data dibatalkan."<<endl;
        return;
    }
       if(height(pohon) == 0)
       {
              if( curr->kiri== NULL && curr->kanan == NULL)
              {
                     (*root) = NULL;
                    
                     return;
              }
       }
       else if(height(pohon) > 0)
       {
              
              if( curr->kiri== NULL && curr->kanan == NULL)
              {
                     
                     if(parent->kiri == curr)
                     {
                           
                           parent->kiri = NULL;
                           delete curr;
                     }
                     else 
                     {
                           
                           parent->kanan = NULL;
                           delete curr;
                     }

                     return;
              }

              
              if((curr->kiri == NULL && curr->kanan != NULL)|| (curr->kiri != NULL && curr->kanan == NULL))
              {

                     if(curr->kiri == NULL && curr->kanan != NULL)
                     {
                           
                           if(parent->kiri == curr)
                           {
                              parent->kiri = curr->kanan;
                              delete curr;
                         }
                         else 
                         {
                              
                              parent->kanan = curr->kanan; 
                              delete curr;
                         }
                     }
                  else 
                  {
                           
                           if(parent->kiri == curr)
                           {
                                  parent->kiri = curr->kiri; 
                                  delete curr;
                           }
                           else 
                           {
                               parent->kanan = curr->kiri; 
                               delete curr;
                            }
                   }
                   return;
              }


              if (curr->kiri != NULL && curr->kanan != NULL)
              {
                     Node* bantu;
                     bantu = curr->kanan;

                     if((bantu->kiri == NULL) && (bantu->kanan == NULL))
                     {
                           curr = bantu;
                           delete bantu;
                           curr->kanan = NULL;
                     }
                     else
                     {
                           if((curr->kanan)->kiri != NULL)
                           {
                                  Node* bantu2;
                                  Node* bantu3;
                                  bantu3 = curr->kanan;         
                                  bantu2 = (curr->kanan)->kiri; 

                                  while(bantu2->kiri != NULL)
                                  {
                                         bantu3 = bantu2;
                                         bantu2 = bantu2->kiri;
                                  }
                                  
                                  curr->data = bantu2->data;
                                  delete bantu2;
                                  bantu3->kiri = NULL;
                        }
                        else 
                        {
                              Node* tmp;
                              tmp = curr->kanan;
                              curr->data = tmp->data;
                              curr->kanan = tmp->kanan;
                              delete tmp;
                        }

                     }
                     return;
              }
       }
}

//fungsi utama
int main()
{
      //deklarasikan variabel
      int pil, data;// c;
      int del, cari;
      Node *pohon; //*t;
      pohon = NULL; //inisialisasi node pohon
      //perulangan do-while
      do
      {
            system("cls"); //bersihkan layar
            printf("\t#PROGRAM TREE C++#");
            printf("\n\t==================");
            printf("\nMENU");
            printf("\n----\n");
            printf("1. Tambah\n");
            printf("2. Lihat pre-order\n");
            printf("3. Lihat in-order\n");
            printf("4. Lihat post-order\n");
            printf("5. Hitung jumlah Node\n");
            printf("6. Search\n");
            printf("7. Hapus data");
            printf("8. Reset data");
            printf("9. Exit\n");
            printf("Pilihan : ");
            scanf("%d", &pil);
            switch(pil)
            {
            //jika pil bernilai 1
            case 1 :
                  printf("\nINPUT : ");
                  printf("\n-------");
                  printf("\nData baru : ");
                  scanf("%d", &data);
                  //panggil fungsi untuk menambah node yang berisi data pada tree
                  tambah(&pohon, data);
                  break;
                 
            //jika pil bernilai 2
            case 2 :
                  printf("\nOUTPUT PRE ORDER : ");
                  printf("\n------------------\n");
                  if(pohon!=NULL)
                       //panggil fungsi untuk mencetak data secara preOrder
                        preOrder(pohon);
                  else
                        printf("Masih kosong!");
                  break;
                 
            //jika pil bernilai 3
            case 3 :
                  printf("\nOUTPUT IN ORDER : ");
                  printf("\n------------------\n");
                  if(pohon!=NULL)
                       //panggil fungsi untuk mencetak data secara inOrder
                        inOrder(pohon);
                  else
                        printf("Masih kosong!");
                  break;
           
            //jika pil bernilai 4
            case 4 :
                  printf("\nOUTPUT POST ORDER : ");
                  printf("\n------------------\n");
                  if(pohon!=NULL)
                       //panggil fungsi untuk mencetak data secara postOrder
                        postOrder(pohon);
                  else
                        printf("Masih kosong!");
                  break;
            
			//jika pil bernilai 5
			case 5 :
				printf("\n Hitung jumlah Node : ");
				printf("\n--------------------\n");
				printf("\nJumlah Node :  %d", count(pohon));
				
				_getch();
				break;
			
			//jika pil bernilai 6
			case 6 :
				printf("\n Search : ");
				printf("\n-----------\n");
				if(pohon!=NULL)
                     {
                           //panggil fungsi untuk mencetak data secara   preOrder
                           printf("\nPRE ORDER  : ");
                           preOrder(pohon); //panggil fungsi
                           printf("\nIN ORDER   : ");
                           inOrder(pohon); //panggil fungsi
                           printf("\nPOST ORDER : ");
                           postOrder(pohon); //panggil fungsi
                           printf("\n\nPENCARIAN DATA");
                           printf("\n--------------");
                           printf("\nMasukkan data yang ingin dicari : ");
                           scanf("%d", &search);
                           //panggil fungsi untuk melakukan pencarian data pada tree
                           void search(Node **root, int cari);
                     }
                     else
                           printf("\nMasih kosong!");

                     _getch();
                     break;
                
                //jika pil bernilai 7
				case 7:
                     if(pohon!=NULL)
                     { 
                           printf("\n\nMenghapus Node : ");
                           printf("\n------------------\n");
                           printf("Masukkan Node yang ingin dihapus: ");
                           scanf("%d", &del);
                        
                           hapus(&pohon, del);
                           printf("\n\nSetelah Node Dihapus : ");
                           printf("\n---------------------- ");
                           printf("\n In-Order	: ");
                           inOrder(pohon); 
                           printf("\n Pre-Order   : ");
                           preOrder(pohon); 
                           printf("\n Post-Order : ");
                           postOrder(pohon); 
                     }
                     else
                           printf("\n Warning : Tree masih kosong!");

                     _getch();
                     break;

				//jika pil bernilai 8
              case 8:
                     pohon=NULL;
                     printf("\nWarning	: Pengosongan Semua Node!! ");
                     printf("\n------------------");
                     printf("\nTree sudah kosong!!");
                      
                     _getch();
                     break;
                     
                    
            }
            _getch();
      }while(pil != 9); //akan diulang jika input tidak samadengan 9
      return EXIT_FAILURE;
}

