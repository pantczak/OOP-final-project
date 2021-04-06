//
// Created by student on 18.01.2020.
//

#ifndef SERWIS_SPRZETU_KOMPUTEROWEGO_REPOSITORY_HPP
#define SERWIS_SPRZETU_KOMPUTEROWEGO_REPOSITORY_HPP

#include <vector>
#include <memory>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <algorithm>
#include "RepositoryException.hpp"

template<class T>
class Repository {
private:
    std::vector<std::shared_ptr<T>> content;
public:
    void create(std::shared_ptr<T> element);

    void remove(std::shared_ptr<T> element);

    std::shared_ptr<T> find(boost::uuids::uuid UUID);

    std::shared_ptr<T> &get(boost::uuids::uuid UUID);

    const std::vector<std::shared_ptr<T>> &getAll();

    Repository();

    virtual ~Repository();
};

template<class T>
void Repository<T>::create(std::shared_ptr<T> element) {
    if (find(element->getId()) == nullptr)
    {
        content.push_back(element);
    } else
    {
        throw RepositoryException("Element already in repository");
    };
}

template<class T>
void Repository<T>::remove(std::shared_ptr<T> element) {
    if (find(element->getId()) != nullptr)
        content.erase(std::find(content.begin(), content.end(), element));
    else
    {
        throw RepositoryException("No element in repository");
    }
}

template<class T>
std::shared_ptr<T> Repository<T>::find(boost::uuids::uuid UUID) {
    for (int i = 0; i < (int) content.size(); i++)
    {
        if (content[i]->getId() == UUID) return content[i];
    }
    return nullptr;
    // throw RepositoryException("No element found with ID: " + boost::uuids::to_string(UUID));
}

template<class T>
std::shared_ptr<T> &Repository<T>::get(boost::uuids::uuid UUID) {
    for (int i = 0; i < (int) content.size(); i++)
    {
        if (content[i]->getId() == UUID) return content[i];
    }
    throw RepositoryException("No element with ID: " + boost::uuids::to_string(UUID));
}

template<class T>
const std::vector<std::shared_ptr<T>> &Repository<T>::getAll() {
    return content;
}

template<class T>
Repository<T>::Repository() = default;

template<class T>
Repository<T>::~Repository() = default;


#endif //SERWIS_SPRZETU_KOMPUTEROWEGO_REPOSITORY_HPP
