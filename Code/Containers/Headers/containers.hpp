#ifndef CONTAINERS_HPP_INCLUDED
#define CONTAINERS_HPP_INCLUDED

#include "Entities/Headers/entidades.hpp"
#include <map>
#include <string>

/**
 * @brief Classe genérica para armazenar e gerenciar pares de chave e valor.
 * * Esta classe utiliza um std::map internamente para armazenar os dados, 
 * o que garante que as chaves sejam únicas e permite operações de busca,
 * inserção, remoção e atualização eficientes.
 * * @tparam K O tipo de dado utilizado para a chave.
 * @tparam V O tipo de dado utilizado para o valor (item) associado à chave.
 */
template <typename K, typename V>
class Container {
    private:
        /**
         * @brief Contêiner interno do tipo mapa que armazena os dados.
         */
        std::map<K, V> container;

    public:
        /**
         * @brief Inclui um novo item no contêiner.
         * * @param chave A chave identificadora do item a ser incluído.
         * @param item O valor do item a ser armazenado.
         * @return true Se o item foi incluído com sucesso.
         * @return false Se já existir um item com a mesma chave no contêiner.
         */
        bool incluir(const K& chave, const V& item);

        /**
         * @brief Remove um item do contêiner com base na sua chave.
         * * @param chave A chave do item que se deseja remover.
         * @return true Se o item foi encontrado e removido com sucesso.
         * @return false Se a chave não for encontrada no contêiner.
         */
        bool remover(const K& chave);

        /**
         * @brief Pesquisa por um item no contêiner utilizando a sua chave.
         * * Se a chave for encontrada, o valor associado a ela será copiado para
         * o endereço de memória apontado pelo parâmetro `item`.
         * * @param chave A chave do item a ser pesquisado.
         * @param item Ponteiro onde o valor encontrado será armazenado.
         * @return true Se a chave for encontrada no contêiner.
         * @return false Se a chave não for encontrada.
         */
        bool pesquisar(const K& chave, V* item); 

        /**
         * @brief Atualiza o valor de um item existente no contêiner.
         * * @param chave A chave do item que terá seu valor atualizado.
         * @param item O novo valor que substituirá o valor antigo.
         * @return true Se o item foi encontrado e atualizado com sucesso.
         * @return false Se a chave não for encontrada no contêiner.
         */
        bool atualizar(const K& chave, const V& item);
};

template <typename K, typename V>
bool Container<K, V>::incluir(const K& chave, const V& item) {
    // map::insert tenta inserir o par (chave, valor).
    // Ele retorna um par onde o 'second' é um bool indicando se a inserção ocorreu.
    // Retornará false se a chave já existir no mapa.
    auto resultado = container.insert({chave, item});
    return resultado.second; 
}

template <typename K, typename V>
bool Container<K, V>::remover(const K& chave) {
    // map::erase remove o elemento pela chave e retorna a quantidade de itens removidos.
    // Como chaves no map são únicas, retornará 1 (sucesso) ou 0 (falha/não encontrado).
    return container.erase(chave) > 0;
}

template <typename K, typename V>
bool Container<K, V>::pesquisar(const K& chave, V* item) {
    // map::find busca a chave e retorna um iterador.
    auto it = container.find(chave);
    
    // Compara com map::end() para checar se encontrou algo
    if (it != container.end()) {
        // Se o ponteiro passado não for nulo, copiamos o valor encontrado para ele
        if (item != nullptr) {
            *item = it->second; 
        }
        return true; // Encontrado
    }
    return false; // Não encontrado
}

template <typename K, typename V>
bool Container<K, V>::atualizar(const K& chave, const V& item) {
    auto it = container.find(chave);
    
    // Só atualizamos se o elemento já existir (para não criar acidentalmente)
    if (it != container.end()) {
        it->second = item; // Substitui o valor antigo pelo novo
        return true;
    }
    return false; // Falhou porque a chave não existe
}

#endif // CONTAINERS_HPP_INCLUDED