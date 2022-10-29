#include <iostream>
using namespace std;
const char *nombre_archivo = "archivo.dat";
struct Estudiante{
    int edad;
    char nombres[50];
    char apellidos[50];
    int telefono;
};
void Leer();
void Crear();
void borrar();
void actulizar();

main() {
        Leer();
        Crear();
        borrar();
        actulizar();
        
        system("pause");
}
void Leer(){
	system("cls");
	FILE* archivo = fopen(nombre_archivo,"rb");
	if (!archivo){
		archivo = fopen(nombre_archivo,"w+b");
	}
	Estudiante estudiante;
	int id=0; // indice o pocision del registro(fila) dentro del archivo
	fread(&estudiante,sizeof(Estudiante),1,archivo);
	cout<<"___________________________________________________"<<endl;
	cout<<"id"<<"|"<<"edad"<<"|"<<"   nombres  "<<"|"<<"   apellidos   "<<"|"<<" telefono"<<endl;
	do{
		cout<<id<<"|"<<estudiante.edad<<"|"<<estudiante.nombres<<"|"<<estudiante.apellidos<<"|"<<estudiante.telefono<<endl;
		fread(&estudiante,sizeof(Estudiante),1,archivo);
		id+=1;
	}while(feof(archivo)==0);
	fclose(archivo);
}
void Crear(){
    FILE* archivo = fopen(nombre_archivo,"a+b");
    char res;
    Estudiante estudiante;
    do
    {
        fflush(stdin);
        cout<<"ingrese edad:";
        cin>>estudiante.edad;
        cin.ignore();

        cout<<"ingrese nombres:";
        cin.getline(estudiante.nombres,50);

        cout<<"ingrese apellidos:";
        cin.getline(estudiante.apellidos,50);

        cout<<"ingrese telefono:";
        cin>>estudiante.telefono;

        fwrite(&estudiante,sizeof(Estudiante),1,archivo);   

        cout<<"desea ingresar otro estudiante (s/n):";
        cin>>res;
        
    } while (res=='s' || res=='S'); 
    
    fclose(archivo);
    Leer();
}

void actulizar(){
    FILE* archivo = fopen(nombre_archivo,"r+b");   
    Estudiante estudiante; 
    int id=0;
    cout<<"ingrese el id que desea modificar:";
    cin>>id;
    fseek(archivo,id * sizeof(Estudiante),SEEK_SET);

        cout<<"ingrese edad:";
        cin>>estudiante.edad;
        cin.ignore();

        cout<<"ingrese nombres:";
        cin.getline(estudiante.nombres,50);

        cout<<"ingrese apellidos:";
        cin.getline(estudiante.apellidos,50);

        cout<<"ingrese telefono:";
        cin>>estudiante.telefono;

        fwrite(&estudiante,sizeof(Estudiante),1,archivo);
    
    fclose(archivo);
    Leer();
}

void borrar(){
    const char *nombre_archivo_temp = "archivo_temp.dat";
    FILE* archivo_temp = fopen(nombre_archivo_temp,"w+b");
    FILE* archivo = fopen(nombre_archivo,"rb");
    Estudiante estudiante;
    int id=0,id_n=0;
    cout<<"ingrese el id a eliminar:";
    cin>>id;

    while (fread(&estudiante,sizeof(Estudiante),1,archivo)){
        if(id_n !=id){
            fwrite(&estudiante,sizeof(Estudiante),1,archivo_temp);
        }
        id_n++;
     }

    fclose(archivo);
    fclose(archivo_temp);

    archivo_temp = fopen(nombre_archivo_temp,"rb");
    archivo = fopen(nombre_archivo,"wb");
    

    while (fread(&estudiante,sizeof(Estudiante),1,archivo_temp)){    
        fwrite(&estudiante,sizeof(Estudiante),1,archivo);
    }
    fclose(archivo);
    fclose(archivo_temp);
    Leer(); 

}






