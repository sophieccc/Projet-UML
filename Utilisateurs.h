
#if ! defined ( UTILISATEURS_H )
#define UTILISATEURS_H


class Utilisateurs 
{

public:

    Utilisateurs ( const Utilisateurs & unUtilisateurs );

    Utilisateurs();

    Utilisateurs(string id, string password);

    virtual ~Utilisateurs();

    string getId();
    string getPassword();

protected:
    string id;
    string password;

};

#endif // UTILISATEURS_H
