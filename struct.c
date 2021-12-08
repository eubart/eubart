#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<time.h>

typedef  struct {
    char Quadra [ 100 ], bairro [ 100 ];
    int casa, CEP;
} endereco;

typedef  struct {
    int ID, idade;
    nomedocaractere[ 100 ], sexo[ 10 ], email[ 100 ];
    altura dupla ;
    bool vacina;
    endereco endereco;
} dadosUser;

typedef  struct {
    int quantUsers, posCad, posedit, posSalva, posExc, posEdit, pos, i, backContUser;
} contadores;

typedef  struct {
    int IDBusca, achou;
    char emailBusca [ 100 ];
} complementar;

typedef  struct {
    int choiceInic, final, choiceCad, choiceExc, choiceFinalExc, buscaExc, escID, choiceEdit, buscaEdit, choiceFinalEdit, backIn, choiceFinalBack;
} escolhas;

void  inicializarStruct (dadosUser * inCadUser, contadores * inCounts, options * inChoices, complementares * inComp); // editar todas as var
void  pegaID (dadosUser * CadUser, contadores * Counts);
void  pegaNome (dadosUser * CadUser);
void  pegaIdade (dadosUser * CadUser);
void  pegaSexo (dadosUser * CadUser);
void  pegaAltura (dadosUser * CadUser);
void  pegaEndereco (dadosUser * CadUser);
void  pegaVacina (dadosUser * CadUser);
void  pegaEmail (dadosUser * CadUser);
void  printUser (dadosUser * printUser);
void  saveBack (dadosUser * saveBack, dadosUser * user, contadores * backCounts);
void  fazBack (dadosUser * saveBack, dadosUser * user, contadores * backCounts);
void  buscaID (dadosUser * User, contadores * Counts, complementar * comp);
void  buscaEmail (dadosUser * User, contadores * Counts, complementar * comp);
void  limpaTela ();
void  statusQuant (contadores * contagens);

int  main () {
    int i = 0 ;
    dadosUser cadUser [ 1000 ];
    dadosUser backupUser [ 1000 ];
    contagem de contadores;
    escolhas escolhas;
    comp complementar;

    for ( int j = 0 ; j! = 1000 ; j ++)
        inicializarStruct (& cadUser [j], & count, & choices, & comp);

    faça {
        faça {
            TelaTela ();
            printf ( " Bem vindo ao menu \ n Escolha uma opção que deseja \ n \ n " );
            statusQuant (& count);
            printf ( " \ n Digite 1 - Caso queira registrar novos usuarios \ n Digite 2 - Caso queira excluir algum usuario \ n Digite 3 - Caso queira editar os dados de algum usuario \ n Digite 4 - Caso queira abrir o menu de Backup \ n Digite 5 - Caso queira ver a lista de todos os cadastros \ n Digite 6 - Caso queira encerrar a sessao \ n " );
            scanf ( " % d " , & escolhas. choiceInic );
            switch (escolhas. choiceInic ) {
            caso  1 : // Cadastrar usuario
                TelaTela ();
                printf ( " _________________Cadastro___________________ \ n " );
                printf ( " Preencha os dados a seguir para concluir o cadastro \ n " );

                faça {
                    pegaID (& cadUser [count. quantUsers ], & count);
                    pegaNome (& cadUser [count. quantUsers ]);
                    pegaIdade (& cadUser [count. quantUsers ]);
                    pegaSexo (& cadUser [contagem. quantUsers ]);
                    pegaAltura (& cadUser [count. quantUsers ]);
                    pegaEndereco (& cadUser [contagem. quantUsers ]);
                    pegaVacina (& cadUser [count. quantUsers ]);
                    pegaEmail (& cadUser [count. quantUsers ]);

                    TelaTela ();

                    printUser (& cadUser [count. quantUsers ]);

                    contar. quantUsers ++;
                    statusQuant (& count);
                    faça {
                        printf ( " Deseja cadastrar mais alguem? 1 - SIM 2 - NAO \ n " );
                        scanf ( " % d " , & escolhas. choiceCad );
                    } while (escolhas. choiceCad < 1 && choices. choiceCad > 2 );
                } while (escolhas. choiceCad ! = 2 );
                pausa ;

            caso  2 : // Excluir usuario
                TelaTela ();
                printf ( " _________________Excluir___________________ \ n " );
                printf ( " Preencha os dados a seguir para excluir um usuário \ n " );

                if (count. quantUsers > 0 ) {
                    faça {
                        faça {
                            printf ( " Sabe o ID ou email do usuario? 1-SIM 2-NAO \ n " );
                            scanf ( " % d " , & escolhas. choiceExc );
                        } while (escolhas. choiceExc < 1 && choices. choiceExc > 2 );

                        switch (escolhas. choiceExc ) {
                        caso  1 :
                            faça {
                                printf ( " Deseja encontrar o usuário através do ID ou Email? 1-ID 2-EMAIL \ n " );
                                scanf ( " % d " , & escolhas. buscaExc );
                            } enquanto (escolhas. buscaExc < 1 && escolhas. buscaExc > 2 );

                            switch (escolhas. buscaExc ) {
                                caso  1 :
                                    printf ( " Qual o ID que deseja? \ n " );
                                    scanf ( " % d " , & comp. IDBusca );
                                    para (contagem. i = 0 ; contagem. i ! = contagem. usuários quant ; contagem. i ++)
                                        buscaID (& cadUser [count. i ], & count, & comp);
                                    
                                    if (comp. achou == 1 ) {
                                        contar. posExc = contagem. pos ;
                                        for (; contagem. posExc ! = contagem. usuários quant ; contagem. posExc ++) {
                                            for ( int j = contagem. posExc + 1 ; j! = contagem. quantUsers ; j ++) {
                                                cadUser [contagem. posExc ]. ID = cadUser [j]. ID ;
                                                cadUser [contagem. posExc ]. altura = cadUser [j]. altura ;
                                                cadUser [contagem. posExc ]. vacina = cadUser [j]. vacina ;
                                                strcpy (cadUser [contagem. posExc ]. nome , cadUser [j]. nome );
                                                strcpy (cadUser [contagem. posExc ]. email , cadUser [j]. email );
                                                strcpy (cadUser [contagem. posExc ]. sexo , cadUser [j]. sexo );
                                                strcpy (usuário cad [contagem. posExc ]. endereco . bairro , usuário cad [j]. endereco . bairro );
                                            }
                                        }
                                        contar. quantUsers -;
                                        statusQuant (& count);
                                    } else {
                                        printf ( " Valor nao encontrado \ n Digite um inteiro para seguir \ n " );
                                        scanf ( " % d " , & i);
                                        i = 0 ;
                                    }
                                    pausa ;

                                caso  2 :
                                    printf ( " Qual o email que deseja? \ n " );
                                    fflush (stdin);
                                    fgets (comp. emailBusca , 100 , stdin);

                                    para (contagem. i = 0 ; contagem. i ! = contagem. usuários quant ; contagem. i ++)
                                        buscaEmail (& cadUser [count. i ], & count, & comp);

                                    if (comp. achou == 1 ) {
                                        contar. posExc = contagem. pos ;
                                        for (; contagem. posExc ! = contagem. usuários quant ; contagem. posExc ++) {
                                            for ( int j = contagem. posExc + 1 ; j! = contagem. quantUsers ; j ++) {
                                                cadUser [contagem. posExc ]. ID = cadUser [j]. ID ;
                                                cadUser [contagem. posExc ]. altura = cadUser [j]. altura ;
                                                cadUser [contagem. posExc ]. vacina = cadUser [j]. vacina ;
                                                strcpy (cadUser [contagem. posExc ]. nome , cadUser [j]. nome );
                                                strcpy (cadUser [contagem. posExc ]. email , cadUser [j]. email );
                                                strcpy (cadUser [contagem. posExc ]. sexo , cadUser [j]. sexo );
                                                strcpy (usuário cad [contagem. posExc ]. endereco . bairro , usuário cad [j]. endereco . bairro );
                                            }
                                        }
                                    contar. quantUsers -;
                                    statusQuant (& count);
                                    } else {
                                        printf ( " Valor nao encontrado \ n " );
                                        scanf ( " % d " , & i);
                                        i = 0 ;
                                    }
                                    pausa ;
                            }
                            pausa ;

                        caso  2 :
                            for ( int i = 0 ; i! = count. quantUsers ; i ++) {
                            printf ( " A posicao: % d \ n " , i);
                            printUser (& cadUser [i]);
                            }

                            faça {
                                printf ( " Qual destes deseja excluir? \ n " );
                                scanf ( " % d " , & escolhas. buscaExc );
                            } while (escolhas. buscaExc < 0 || escolhas. buscaExc > contagem. quantUsers );

                            contar. posExc = escolhas. buscaExc ;

                            for (; contagem. posExc ! = contagem. usuários quant ; contagem. posExc ++) {
                                for ( int j = contagem. posExc + 1 ; j! = contagem. quantUsers ; j ++) {
                                    cadUser [contagem. posExc ]. ID = cadUser [j]. ID ;
                                    cadUser [contagem. posExc ]. altura = cadUser [j]. altura ;
                                    cadUser [contagem. posExc ]. vacina = cadUser [j]. vacina ;
                                    strcpy (cadUser [contagem. posExc ]. nome , cadUser [j]. nome );
                                    strcpy (cadUser [contagem. posExc ]. email , cadUser [j]. email );
                                    strcpy (cadUser [contagem. posExc ]. sexo , cadUser [j]. sexo );
                                    strcpy (usuário cad [contagem. posExc ]. endereco . bairro , usuário cad [j]. endereco . bairro );
                                }
                            }
                            contar. quantUsers -;
                            statusQuant (& count);
                            pausa ;
                        }
                        faça {
                            printf ( " Deseja excluir mais algum usuário? 1-SIM 2-NAO \ n " );
                            scanf ( " % d " , & escolhas. choiceFinalExc );
                        } while (escolhas. choiceFinalExc < 1 && escolhas. choiceFinalExc > 2 );
                    } while (opções. choiceFinalExc ! = 2 );
                } else {
                    printf ( " Quantidade insuficiente de usuários \ n Digite um inteiro para seguir \ n " );
                    scanf ( " % d " , & i);
                    i = 0 ;
                }
                pausa ;

            case  3 : // Editar usuario
                TelaTela ();
                printf ( " _________________Editar___________________ \ n " );
                printf ( " Preencha os dados a seguir para editar um usuário \ n " );

                if (count. quantUsers > 0 ) {
                    faça {
                        faça {
                            printf ( " Sabe o ID ou email do usuario? 1-SIM 2-NAO \ n " );
                            scanf ( " % d " , & escolhas. choiceEdit );
                        } while (escolhas. choiceEdit < 1 && choices. choiceEdit > 2 );

                        switch (escolhas. choiceEdit ) {
                        caso  1 :
                            faça {
                                printf ( " Deseja encontrar o usuário através do ID ou Email? 1-ID 2-EMAIL \ n " );
                                scanf ( " % d " , & escolhas. buscaEdit );
                            } while (escolhas. buscaEdit < 1 && choices. buscaEdit > 2 );
                            switch (escolhas. buscaEdit ) {
                            caso  1 :
                                printf ( " Qual o ID que deseja? \ n " );
                                scanf ( " % d " , & comp. IDBusca );

                                para (contagem. i = 0 ; contagem. i <contagem. usuários quant ; contagem. i ++)
                                    buscaID (& cadUser [count. i ], & count, & comp);

                                if (comp. achou == 1 ) {
                                    contar. posEdit = count. pos ;
                                    pegaNome (& cadUser [contagem. posEdit ]);
                                    pegaIdade (& cadUser [contagem. posEdit ]);
                                    pegaSexo (& cadUser [contagem. posEdit ]);
                                    pegaAltura (& cadUser [contagem. posEdit ]);
                                    pegaEndereco (& cadUser [contagem. posEdit ]);
                                    pegaVacina (& cadUser [contagem. posEdit ]);
                                    pegaEmail (& cadUser [contagem. posEdit ]);

                                    printUser (& cadUser [escolhas. buscaEdit ]);
                                } else {
                                    printf ( " Valor nao encontrado \ n Digite um inteiro para seguir \ n " );
                                    scanf ( " % d " , & i);
                                    i = 0 ;
                                }
                                pausa ;
                            caso  2 :
                                printf ( " Qual o e-mail que deseja \ n " );
                                fflush (stdin);
                                fgets (comp. emailBusca , 100 , stdin);

                                para (contagem. i = 0 ; contagem. i ! = contagem. usuários quant ; contagem. i ++)
                                    buscaEmail (& cadUser [count. i ], & count, & comp);

                                if (comp. achou == 1 ) {
                                    contar. posEdit = count. pos ;
                                    pegaNome (& cadUser [contagem. posEdit ]);
                                    pegaIdade (& cadUser [contagem. posEdit ]);
                                    pegaSexo (& cadUser [contagem. posEdit ]);
                                    pegaAltura (& cadUser [contagem. posEdit ]);
                                    pegaEndereco (& cadUser [contagem. posEdit ]);
                                    pegaVacina (& cadUser [contagem. posEdit ]);
                                    pegaEmail (& cadUser [contagem. posEdit ]);

                                    printUser (& cadUser [escolhas. buscaEdit ]);
                                } else {
                                    printf ( " Valor nao encontrado \ n Digite um inteiro para seguir \ n " );
                                    scanf ( " % d " , & i);
                                    i = 0 ;
                                }
                                pausa ;
                            }
                            pausa ;

                        caso  2 :
                            for ( int i = 0 ; i! = count. quantUsers ; i ++) {
                                printf ( " A posicao: % d \ n " , i);
                                printUser (& cadUser [i]);
                            }
                            faça {
                                printf ( " Qual destes deseja editar? \ n " );
                                scanf ( " % d " , & escolhas. buscaEdit );
                            } while (escolhas. buscaEdit < 0 || escolhas. buscaEdit > contagem. quantUsers );
                            pegaNome (& cadUser [escolhas. buscaEdit ]);
                            pegaIdade (& cadUser [escolhas. buscaEdit ]);
                            pegaSexo (& cadUser [escolhas. buscaEdit ]);
                            pegaAltura (& cadUser [escolhas. buscaEdit ]);
                            pegaEndereco (& cadUser [escolhas. buscaEdit ]);
                            pegaVacina (& cadUser [escolhas. buscaEdit ]);
                            pegaEmail (& cadUser [escolhas. buscaEdit ]);

                            printUser (& cadUser [escolhas. buscaEdit ]);
                            pausa ;
                        }
                        faça {
                            printf ( " Deseja editar mais algum usuario? 1-SIM 2-NAO \ n " );
                            scanf ( " % d " , & escolhas. choiceFinalEdit );
                        } while (escolhas. choiceFinalEdit < 1 && escolhas. choiceFinalEdit > 2 );
                    } while (escolhas. choiceFinalEdit ! = 2 );
                } else {
                    printf ( " Quantidade insuficiente de usuários \ n Digite um inteiro para seguir \ n " );
                    scanf ( " % d " , & i);
                    i = 0 ;
                }
                pausa ;

            case  4 : // Backup
                TelaTela ();
                printf ( " _________________Backup___________________ \ n " );
                printf ( " Preencha os dados a seguir para fazer o backup dos usuários \ n " );
                printf ( " O backup salvara todos os dados atuais, e quando necessario, ira substituir todos os presentes naquele momento \ n " );

                faça {
                    faça {
                        printf ( " Digite 1 - Para salvar os usuarios atuais \ n Digite 2 - Para recuperar os usuarios salvos \ n " );
                        scanf ( " % d " , & escolhas. backIn );
                    } while (escolhas. backIn > 2 || escolhas. backIn < 1 );

                    if (count. quantUsers > 0 ) {
                        switch (opções. backIn ) {
                        caso  1 :
                            para (contagem. i = 0 ; contagem. i <contagem. usuários quant ; contagem. i ++) {
                                printUser (& cadUser [contagem. i ]);
                                saveBack (& backupUser [contagem. i ], & cadUser [contagem. i ], & contagem);
                            }

                            printf ( " O backup foi salvo com sucesso \ n Digite um inteiro para seguir \ n " );
                            scanf ( " % d " , & i);
                            i = 0 ;
                            pausa ;

                        caso  2 :
                            para (contagem. i = 0 ; contagem. i <contagem. usuários quant ; contagem. i ++) {
                                fazBack (& backupUser [contagem. i ], & cadUser [contagem. i ], & contagem);
                                printUser (& cadUser [contagem. i ]);
                            }
                            printf ( " O backup foi realizado com sucesso \ n Digite um inteiro para seguir \ n " );
                            scanf ( " % d " , & i);
                            i = 0 ;
                            pausa ;
                        }
                    } else {
                        printf ( " Quantia insuficiente de usuarios, faca pelo menos um cadastro \ n Digite um inteiro para seguir \ n " );
                        scanf ( " % d " , & i);
                        i = 0 ;
                    }
                    faça {
                        printf ( " Deseja fazer algo a mais no backup? 1-SIM 2-NAO \ n " );
                        scanf ( " % d " , & escolhas. choiceFinalBack );
                    } while (escolhas. choiceFinalBack < 1 && escolhas. choiceFinalBack > 2 );
                } while (escolhas. choiceFinalBack ! = 2 );
                pausa ;

            case  5 : // printa usuarios
                TelaTela ();
                printf ( " O total de usuários: % d \ n " , contagem. quantUsers );

                for ( int i = 0 ; i <count. quantUsers ; i ++) {
                    printf ( " A posicao: % d \ n " , i);
                    printUser (& cadUser [i]);
                }
                printf ( " Digite um inteiro para sair " );
                scanf ( " % d " , & i);
                i = 0 ;
                pausa ;

            case  6 : // Encerrar sessao
                TelaTela ();
                printf ( " Obrigado pelo tempo, até uma próxima vez " );
                escolhas. final = 6 ;
                pausa ;
            }
        } while (escolhas. choiceInic > 6 || escolhas. choiceInic < 1 );
    } enquanto (escolhas. final ! = 6 );
    return  0 ;
}
// Fim da Main

// criação das Funções

void  inicializarStruct (dadosUser * inCadUser, contadores * inCounts, choices * inChoices, complementares * inComp) {
    inCadUser-> ID = 0 ;
    inCadUser-> idade = 0 ;
    inCadUser-> altura = 0 ;

    inCounts-> quantUsers = 0 ;
    inCounts-> posCad = 0 ;
    inCounts-> posSalva = 0 ;

    inChoices-> choiceCad = 0 ;
    inChoices-> final = 0 ;
    inChoices-> choiceInic = 0 ;
    inChoices-> choiceExc = 0 ;
    inChoices-> choiceFinalExc = 0 ;
    inChoices-> buscaExc = 0 ;
    inChoices-> escID = 0 ;

    inComp-> Achou = 0 ;
}

void  limpaTela () {
    printf ( " \ 33 [H \ 33 [2J " );
    sistema ( " cls " );
}

void  pegaID (dadosUser * cadUser, contadores * Counts) {
    int i = 0 ;
    srand ( tempo ( NULL ));
    cadUser-> ID = ( rand ()% ( 999999 - 100.000 + 100.000 ) + 100.000 );
    for (i = Contagens-> usuáriosquant - 1 ; i! = Contagens-> Usuáriosquant ; i ++) {
        if (cadUser-> ID == cadUser [i]. ID ) {
            cadUser-> ID = ( rand ()% ( 999999 - 100.000 + 100.000 ) + 100.000 );
            i = 0 ;
        }
    }
}

void  pegaNome (dadosUser * cadUser) {
    faça {
        printf ( " Qual o nome do usuário? \ n " );
        fflush (stdin);
        fgets (cadUser-> nome , 100 , stdin);
    } while ( strlen (cadUser-> nome ) < 2 );
}

void  pegaIdade (dadosUser * cadUser) {
    faça {
        printf ( " Qual a idade do usuário? \ n " );
        scanf ( " % d " , & cadUser-> idade );
    } while (cadUser-> idade < 0 || cadUser-> idade > 100 );
}

void  pegaSexo (dadosUser * cadUser) {
    int i = 1 ;
    faça {
        printf ( " Qual o sexo do usuário? Homem, Mulher ou NDA \ n " );
        fflush (stdin);
        fgets (cadUser-> sexo , 10 , stdin);

        if ( strcmp (cadUser-> sexo , " NDA \ n " ) == 0 || strcmp (cadUser-> sexo , " Mulher \ n " ) == 0 || strcmp (cadUser-> sexo , " Homem \ n " ) == 0 ) {
            i = 0 ;
        }
    } enquanto (i == 1 );
}

void  pegaAltura (dadosUser * cadUser) {
    faça {
        printf ( " Qual a altura do usuario? \ n " );
        scanf ( " % lf " , & cadUser-> altura );
    } while (cadUser-> altura < 1 || cadUser-> altura > 2 );
}

void  pegaEndereco (dadosUser * cadUser) {
    faça {
        printf ( " Qual o bairro do usuario? \ n " );
        fflush (stdin);
        fgets (usuário cad-> endereco . bairro , 100 , stdin);
    } while ( strlen (cadUser-> endereco . bairro ) < 2 );
    faça {
        printf ( " Qual o numero da casa do usuario? \ n " );
        scanf ( " % d " , & cadUser-> endereco . casa );
    } while (cadUser-> endereco . casa < 0 );
    faça {
        printf ( " Qual o CEP do usuario? \ n " );
        scanf ( " % d " , & cadUser-> endereco . CEP );
    } while (cadUser-> endereco . CEP < 0 );
    faça {
        printf ( " Qual a quadra do usuario? \ n " );
        fflush (stdin);
        fgets (cadUser-> endereco . Quadra , 100 , stdin);
    } while ( strlen (cadUser-> endereco . Quadra ) < 2 );
}

void  pegaVacina (dadosUser * cadUser) {
    char pergVacina [ 10 ];
    int i = 0 ;

    faça {
        printf ( " Usuario vacinado? sim ou nao \ n " );
        fflush (stdin);
        fgets (pergVacina, 10 , stdin);

        if ( strcmp (pergVacina, " sim \ n " ) == 0 ) {
            cadUser-> vacina = verdadeiro ;
            i = 1 ;
        }
        else  if ( strcmp (pergVacina, " nao \ n " ) == 0 ) {
            cadUser-> vacina = falso ;
            i = 1 ;
        }
    } enquanto (i! = 1 );
}

void  pegaEmail (dadosUser * cadUser) {
    faça {
        printf ( " Qual o email do usuario? \ n " );
        fflush (stdin);
        fgets (cadUser-> email , 100 , stdin);
    } while ( strchr (cadUser-> email , ' @ ' ) == NULL );
}

void  printUser (dadosUser * printUser) {
    printf ( " ____________________________________ \ n " );
    printf ( " \ n ID: % d \ n " , printUser-> ID );
    printf ( " Nome: % s " , printUser-> nome );
    printf ( " Sexo: % s " , printUser-> sexo );
    printf ( " Idade: % d \ n " , printUser-> idade );
    printf ( " Altura: % .2lf \ n " , printUser-> altura );
    printf ( " Bairro: % s " , printUser-> endereco . bairro );
    printf ( " Numero da casa: % d \ n " , printUser-> endereco . casa );
    printf ( " CEP: % d \ n " , printUser-> endereco . CEP );
    printf ( " Quadra: % s " , printUser-> endereco . Quadra );

    if (printUser-> vacina == true ) {
        printf ( " O usuario tomou vacina \ n \ n " );
    }

    else {
        printf ( " O usuário não tomou vacina \ n \ n " );
    }
    printf ( " ____________________________________ \ n " );
}

void  saveBack (dadosUser * saveBack, dadosUser * user, contadores * backCounts) {
    saveBack-> ID = usuário-> ID ;
    saveBack-> endereco . casa = usuário-> endereco . casa ;
    saveBack-> endereco . CEP = usuário-> endereco . CEP ;
    saveBack-> idade = user-> idade ;
    saveBack-> altura = user-> altura ;
    saveBack-> vacina = utilizador-> vacina ;
    backCounts-> backContUser = backCounts-> quantUsers ;
    strcpy (saveBack-> nome , usuário-> nome );
    strcpy (saveBack-> email , user-> email );
    strcpy (saveBack-> sexo , usuário-> sexo );
    strcpy (saveBack-> endereco . bairro , usuário-> endereco . bairro );
    strcpy (saveBack-> endereco . Quadra , usuário-> endereco . Quadra );
}

void  fazBack (dadosUser * saveBack, dadosUser * user, contadores * backCounts) {
    usuário-> ID = saveBack-> ID ;
    usuário-> endereco . casa = saveBack-> endereco . casa ;
    usuário-> endereco . CEP = saveBack-> endereco . CEP ;
    user-> idade = saveBack-> idade ;
    usuário-> altura = saveBack-> altura ;
    usuário-> vacina = salvarBack-> vacina ;
    backCounts-> quantUsers = backCounts-> backContUser ;
    strcpy (usuário-> nome , saveBack-> nome );
    strcpy (usuário-> email , saveBack-> email );
    strcpy (usuário-> sexo , saveBack-> sexo );
    strcpy (usuário-> endereco . bairro , saveBack-> endereco . bairro );
    strcpy (usuário-> endereco . Quadra , saveBack-> endereco . Quadra );
}

void  buscaID (dadosUser * User, contadores * Counts, complementar * comp) {
    if ( comp- > IDBusca == Usuário- > ID ) {
        Contagens-> pos = Contagens-> i ;
        comp-> achou = 1 ;
    }
}

void  buscaEmail (dadosUser * User, contadores * Counts, complementar * comp) {
    if ( strcmp ( comp- > emailBusca , Usuário- > email ) == 0 ) {
        Contagens-> pos = Contagens-> i ;
        comp-> achou = 1 ;
    }
}

void  statusQuant (contadores * contagens) {
    int i;
    i = contagens-> quantUsers ;
    printf ( " A quantidade de cadastros em aberto: % d \ n A quantidade de cadastros atuais: % d  \ n " , 1000 - i, Contagens-> QuantUsers );
}
