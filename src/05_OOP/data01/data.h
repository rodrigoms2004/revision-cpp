#include <string>

using namespace std;

class Data {

  short m_dia;
  short m_mes;
  short m_ano;
  short m_anoMin, m_anoMax;
  bool m_OK;

public:
  // valores default para os anos mínimo e máximo, e constantes para meses:
  enum { AnoMinDefault = 1 , AnoMaxDefault = 9999 } ;
  
  enum { Janeiro=1, Fevereiro, Marco, Abril, Maio, Junho,
         Julho, Agosto, Setembro, Outubro, Novembro, Dezembro};

  Data ( /* parâmetro oculto */ );
  Data ( /* parâmetro oculto */ short dia, short mes, short ano);

  void altera( /* parâmetro oculto */ short dia, short mes, short ano);

  // apurar o último dia de cada mês:
  // inline char ultimoDiaMes( /*const Data * const this */ ) const;
  // desconbrir de o ano é bissexto:
  // inline bool anoBissexto( /*const Data * const this */ ) const;
  
  // converter dia, mês e ano para uma string e retornar esse string:
  string toString( /*const Data * const this */ ) const;

  // funções inline

  inline bool anoBissexto( /*const Data * const this */ ) const {
    // se não for divisível por 4 não é bissexto:
    if ( m_ano % 4 != 0 ) // ou usando and de bits: if( (m_ano&3) !=0 )
      return false;
    // se divisível por 4 mas não por 100, exceto se divisível por 400, é bissexto:
    return m_ano % 100 != 0 || m_ano % 400 == 0;  
    // nos dois casos acima não podemos usar o and de bits
    // pois, ao contrário de 4, os números 100 e 400 não são potências de 2

  }

  inline char ultimoDiaMes() const {
    if ( m_mes == Fevereiro )
      return ( anoBissexto() ) ? 29 : 28; // usa o operador condicional

    if (m_mes >= Janeiro && m_mes <= Julho) // janeiro a julho exceto fevereiro
      return ( m_mes & 1 ) ? 31 : 30;

    if ( m_mes >= Agosto && m_mes <= Dezembro)
    return (m_mes & 1 ) ? 30 : 31;

    return 0; // mês inválido
  }

  int Compara ( /* const Data * this, */ const Data & other) const;

  // OPERADORES
  inline bool operator==(const Data &other) const {
    return Compara(other) == 0;
  }

  inline bool operator!=(const Data &other) const {
    return Compara(other) != 0;
  }

  inline bool operator>(const Data &other) const {
    return Compara(other) > 0;
  }

  inline bool operator>=(const Data &other) const {
    return Compara(other) >= 0;
  }

  inline bool operator<(const Data &other) const {
    return Compara(other) < 0;
  }

  inline bool operator<=(const Data &other) const {
    return Compara(other) <= 0;
  }
};


