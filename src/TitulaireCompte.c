#include "../include/TitulaireCompte.h"

struct TitulaireCompte_s
{
    int id_client;
    char nom[15];
    char prenom[15];
    int numero_tel;
    char mdp[35];
    Client client_suivant;
};

//TODO VarGlobSize

Client
cr_client(char nom[15], char prenom[15], int numero_tel, char mdp[32]) {
    int i;
    Client res;
    res = malloc(sizeof(Client));
    //TODO: int id_client + incrementer index
    for(i = 0; i < 15; i++) {
        res->nom[i] = nom[i];
    }
    for(i = 0; i < 15; i++) {
        res->prenom[i] = prenom[i];
    }
    for(i = 0; i < 15; i++) {
        res->mdp[i] = mdp[i];
    }    
    res->numero_tel = numero_tel;
    res->client_suivant = NULL;
    //Enregistrer nouveau json
    return res;
}

void
supprimerClient(Client LCClient, Client client){
    //LE CLIENT DOIT EXISTER !!!
    //TODO : remove le json
    Client etude = LCClient;
    if (etude->client_suivant == NULL) {
        LCClient = NULL;
        free(etude);
        return;
    }
    while(etude->client_suivant != client){
        etude = etude->client_suivant;
    }
    etude->client_suivant = client->client_suivant;
    free(client);
}

void
addLCClient(Client LCClient, Client client){
    if (LCClient == NULL) {
        LCClient = client;
    } else {
        Client etude = LCClient;
        while(etude->client_suivant != NULL){
            etude = etude->client_suivant;
        }
        etude->client_suivant = client;
    }    
}

void
setNom(Client client, char nom[15]){
    int i;
    for(i = 0; i < 15; i++)
    {
        client->nom[i] = nom[i];
    }    
}

void
setPrenom(Client client, char prenom[15]){
    int i;
    for(i = 0; i < 15; i++)
    {
        client->prenom[i] = prenom[i];
    } 
}

void
setNum(Client client, int num){
    client->numero_tel = num;
}

void
setMdp(Client client, char mdp[32]){
    int i;
    for(i = 0; i < 32; i++)
    {
        client->mdp[i] = mdp[i];
    } 
}

int
getIdClient(Client client){
    return client->id_client;
}

char *
getNom(Client client){
    return client->nom;
}

char *
getPrenom(Client client){
    return client->prenom;
}

int
getNum(Client client){
    return client->numero_tel;
}

char *
getMdp(Client client){
    return client->mdp;
}