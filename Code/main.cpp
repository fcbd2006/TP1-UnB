#include "ControladorasA/Headers/cai.hpp"
#include "ControladorasA/Headers/cac.hpp"
#include "ControladorasA/Headers/cagh.hpp"
#include "ControladorasA/Headers/cagp.hpp"
#include "ControladorasA/Headers/caa.hpp"
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
