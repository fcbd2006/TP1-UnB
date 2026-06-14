#include "Controladoras/Headers/cai.hpp"
#include "Controladoras/Headers/cac.hpp"
#include "Controladoras/Headers/cagh.hpp"
#include "Controladoras/Headers/cagp.hpp"
#include "Controladoras/Headers/caa.hpp"
#include "Stubs/servico.hpp"

using namespace std;

int main()
{
    CntrIAInicial programa;
    CntrIAAutenticacao auth;
    CntrIACadastro cad;
    CntrIAGestaoHistorias hist;
    CntrIAGestaoProjetos proj;
    auth.setServicoAutenticacao(new StubAutenticacao);
    cad.setServicoCadastro(new StubCadastro);
    hist.setServicoGestaoHistorias(new StubGestaoHistorias);
    programa.setApresentacaoAutenticacao(&auth);
    programa.setApresentacaoCadastro(&cad);
    programa.setApresentacaoHistorias(&hist);
    programa.setApresentacaoProjetos(&proj);

    programa.executar();

    return 0;
}
