#include <sstream> // streams que alimentam uma string
#include <iomanip> // manipuladores de IO
#include "data.h"  // reconhecer os símbolos da class Data
#include <string>

Data::Data( /* Data *this, */ ) // parãmetro oculto cujo nome é "this"
  : m_anoMin(AnoMinDefault) // Inicialização de membros
  , m_anoMax(AnoMaxDefault)
  , m_OK(false)             // C++ tem as palavras reservadas "true" e "false" ...
{
  // se necessário, adquirir recursos aqui (abrir arquivos, etc).
} // Nenhuma outra tarefa deve ser executada na construtora. 

// Implementando a "construtora de conveniência":
Data::Data( /* Data *this, */ short dia, short mes, short ano)
  : m_anoMin(AnoMinDefault) // Inicialização de membros
  , m_anoMax(AnoMaxDefault)
  //, m_OK(false)           // não é preciso inicializar m_OK, pois abaixo será chamada
                            // a função "altera" que atribuirá um valor a m_OK de acordo 
                            // com a correção ou não dos argumentos passados:
{
  altera(dia, mes, ano);
  // se necessário, adquirir recursos aqui (abrir arquivos, etc).
} // Nenhuma outra tarefa deve ser executada na construtora. 

void Data::altera( /* Data *this, */ short dia, short mes, short ano) {
  m_dia = dia;
  m_mes = mes;
  m_ano = ano;
  // análise e validação dos valores recebidos
  // (obs: o exemplo usa 31, como último dia do mês. Mais a frente
  // implementaremos o código para calcular o último dia de cada mês)
  m_OK = m_ano >= m_anoMin && m_ano <= m_anoMax &&
         m_mes >= Janeiro && m_mes <= Dezembro &&
         m_dia >= 1 && m_dia <= ultimoDiaMes(); // depois, trocar 31 por uma chamada à função ultimoDiaMes
}

// converter a data para uma string
string Data::toString( /* const Data *const this */ ) const {
  ostringstream sout; // funciona como "cout" (classes de stream)
                      // mas sua saída é um objeto-membro do tipo std::string
  if (m_OK) {
    sout.fill('0'); // preenchedor à esquerda em função da largura (setw)
    sout << setw(2) << m_dia << '/' << setw(2) << m_mes << '/' << setw(4) << m_ano;
  } else {
    sout << "***ERRO***";
  }
  return sout.str(); // retorna o membro std::string alimentado pelo stream
}

int Data::Compara ( /* const Data * this, */ const Data & other) const {
  if (this->m_ano != other.m_ano)
    return this->m_ano - other.m_ano;
  
  return (this->m_mes != other.m_mes)
    ? this->m_mes - other.m_mes   // true
    : this->m_dia - other.m_dia;  // false

  // e o retorno será:
    // menor que zero se a primeira estiver menor
    // maior que zero se a primeira estiver maior
    // zero, se estiverem iguais.
}


