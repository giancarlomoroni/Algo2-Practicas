template <typename T>
string_map<T>::string_map(){
    _raiz = nullptr;
    _size = 0;
}

template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() { *this = aCopiar; } // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) {
    // COMPLETAR
}

template <typename T>
string_map<T>::~string_map(){
    // COMPLETAR
}

template <typename T>
T& string_map<T>::operator[](const string& clave){
    // COMPLETAR
}

template <typename T>
string string_map<T>::fin(string clave) const {
    for (int i = 0; i < (clave).size()-1; ++i) {
        char temp = (clave)[i];
        (clave)[i] = (clave)[i+1];
        (clave)[i+1] = temp;
    }
    (clave).pop_back();
    return clave;
}

template <typename T>
int string_map<T>::pertenece(string_map::Nodo *raiz, string clave)const{
    if(_size == 0){
        return 0;
    }
    else{
        if(clave == ""){
            if(raiz->definicion != nullptr){
                return 0;
            }
            else{
                return 1;
            }
        }
        else if(raiz->siguientes[int((clave)[0])] != nullptr){
            pertenece(raiz->siguientes[int((clave)[0])],fin(clave));
        }
        else{
            return 0;
        }
    }
}

template <typename T>
int string_map<T>::count(const string& clave) const{
    string copia = clave;
    return pertenece(_raiz,copia);
}

template <typename T>
const T& string_map<T>::at(const string& clave) const {
    Nodo* actual = _raiz;
    for (char c : clave){
        actual = actual->siguientes[int(c)];
    }
    return *(actual->definicion);
}

template <typename T>
T& string_map<T>::at(const string& clave) {
    Nodo* actual = _raiz;
    for (char c : clave){
        actual = actual->siguientes[int(c)];
    }
    return *(actual->definicion);
}

template <typename T>
void string_map<T>::erase(const string& clave) {
    borrar(_raiz,clave);
    _size --;
}

template <typename T>
int string_map<T>::size() const{
    return size;
}

template <typename T>
bool string_map<T>::empty() const{
     return _size == 0;
}

template <typename T>
void string_map<T>::insert(const pair<std::string, T>& valor) {
    if(_raiz == nullptr){
        _raiz = new Nodo();
        Nodo* actual = _raiz;
        for (char c : valor.first) {
            actual->siguientes[int(c)] = new Nodo();
            actual = actual->siguientes[int(c)];
        }
        actual->definicion = new T;
        *(actual->definicion) = valor.second;
        _size ++;
    }
    else{
        if(count(valor.first) == 1){
            (*this)[valor.first] = valor.second;
        }
        else{
            Nodo* actual = _raiz;
            for (char c : valor.first) {
                if(actual->siguientes[int(c)] == nullptr){
                    actual->siguientes[int(c)] = new Nodo();
                    actual = actual->siguientes[int(c)];
                }
                else{
                    actual = actual->siguientes[int(c)];
                }
            }
            actual->definicion = new T;
            *(actual->definicion) = valor.second;
            _size++;
        }
    }

}