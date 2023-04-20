/*
  Arthur Augusto - 202110830
  Davi Gomides - 202020882
  Raynner Taniguchi - 202010167
  Gabriel Silva - 202220171

 * */


#include "iostream"
#include "fstream"
#include "string"

using namespace std;

void read_binary() {
  ifstream binary_file("saida.bin", ios::binary | ios::out);
  
  char buffer[1024];

  if (!binary_file){
    cout << "Não foi possível abrir o arquivo" << endl;
  }
  
  while (binary_file.read(buffer, sizeof(buffer))){
    cout << buffer << " ";
  };
  
  binary_file.close();
}

int main (int argc, char *argv[])
{
  string aux;

  fstream arq_in; 
  fstream arq_out;
  
  arq_in.open("preparatorio4.csv", ios::in);

  if (!arq_in){
    cout << "Não foi possível abrir o arquivo" << endl;
  }
  
  arq_out.open("saida.bin", ios::binary | ios::in | ios::out | ios::trunc);

  if (!arq_out){
    cout << "Não foi possivel abrir o arquivo binário";
  }

  getline(arq_in, aux);
  while (getline(arq_in >> ws, aux) && !arq_in.eof()){
    arq_out.write(reinterpret_cast<char *>(&aux), sizeof(aux));
  }

  arq_in.close();
  arq_out.close();

  read_binary();

  return 0;
}
