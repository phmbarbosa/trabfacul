#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//estrutura de alunos, contendo ID, NOME, CPF, TELEFONE E EMAIL.
struct alunos {
  int aluno_id;
  char nome[300];
  char cpf[14];
  char telefone[50];
  char email[100];
};
//estrutura de professores, contendo ID, NOME, CPF, TELEFONE E EMAIL.
struct professores{
  int professor_id;
  char nome[300];
  char cpf[14];
  char telefone[50];
  char email[100];
};
//estrutura de turmas, contendo id, tipo, dia, horario, id do professor, maximo de alunos, minimo de alunos, faixa etaria.
struct turmas {
  int turma_id;
  char tipo;
  int dia;
  char horario[5];
  int id_professor;
  int minimo_aluno;
  int maximo_aluno;
  char faixa_etaria[5];
};
//estrutura de inscricoes, contendo o id do aluno e da aula.
struct inscricoes{
  int id_aluno;
  int id_aula;
  int qtdAlunoPorAula;
};
//protótipo de funções
void limparLixo(char c);
void ajustCpf(char *cpf);
void ajustTel(char *tel);
void limparTela();
void cadastrarAluno();
void cadastrarProfessor();
void cadastrarTurma();
void inscreverAluno();
void cancelarInscricao();
void fecharTurmas();
void confirmarTurmas();
void verificarFile(FILE *filePointer);
// Programa Principal
int main(void) {
  int opcao = 0;
  //looping enquanto não fecha o programa
  do {
    limparTela();
    
    printf("Bem vindo à Academia Superação!\n\nO que deseja?\n\n");
    
    printf("1 - Cadastrar Aluno;\n2 - Cadastrar Professor;\n3 - Cadastrar Turma;\n4 - Inscrever Aluno;\n5 - Cancelar Inscrição;\n6 - Fechar Turmas;\n7 - Confirmar Turmas;\n8 - Fechar o Programa;\n\nDigite a opção desejada: ");
    scanf("%d",&opcao);
    
    switch (opcao) {
    case 1: // 1- Cadastra aluno
      cadastrarAluno();
      break;
      
    case 2: // 2- Cadastrar professor
      cadastrarProfessor();
      break;

    case 3: // 3- Cadastrar turma
      cadastrarTurma();
      break;

    case 4: // 4- Inscrever aluno
      inscreverAluno();
      break;

    case 5: // 5- Cancelar inscrição
      cancelarInscricao();
      break;

    case 6: // 6- Fechar turmas
      fecharTurmas();
      break;

    case 7: // 7- Confirmar turmas
      confirmarTurmas();
      break;

    case 8: // 9- Fechar o programa
      exit(1);
      break;

    default:
      printf("Opcao invalida, tente novamente.\n");
      break;
    }
    
  }while (opcao > 0 && opcao < 10);

}
// Limpa o buffer para uso do gets
void limparLixo(char c){
  while((c= getchar()) != '\n' && c != EOF);
}
//Função para verificar se o arquivo foi aberto corretamente
void verificarFile(FILE *filePointer){
  if (filePointer == NULL) {
    printf("Erro na abertura do arquivo!!\n");
    exit(1);
  }
}
// Formata o cpf no modelo desejado: XXX.XXX.XXX-XX
void ajustCpf(char *cpf){
  memmove(cpf + 3 + 1, cpf + 3, (14 - 3) + 1);
  cpf[3] = '.';
  memmove(cpf + 7 + 1, cpf + 7, (14 - 7) + 1);
  cpf[7] = '.';
  memmove(cpf + 11 + 1, cpf + 11, (14 - 11) + 1);
  cpf[11] = '-';
}
// limpa a tela para ficar mais fácil de entender
void limparTela(){
  system("clear");
}
// Formata o telefone no modelo desejado: (XX)XXXX-XXXX
void ajustTel(char *tel) {
  memmove(tel + 1, tel, strlen(tel) + 1);
  tel[0] = '(';
  memmove(tel + 3, tel + 2, strlen(tel) - 2 + 1);
  tel[3] = ')';
  memmove(tel + 9, tel + 8, strlen(tel) - 7 + 1);
  tel[9] = '-';
}
// Função para cadastrar os alunos
void cadastrarAluno(){
  char c;
  FILE *fp;
  struct alunos alunos;
  limparTela();
  fp = fopen("alunos.csv","a");
  verificarFile(fp);
  
  printf("Digite o ID do(a) aluno(a): ");
  scanf("%d",&alunos.aluno_id);
  fprintf(fp, "%d,",alunos.aluno_id);
  
  limparLixo(c);
  
  printf("Digite o nome do(a) aluno(a): ");
  gets(alunos.nome);
  fprintf(fp, "%s,",alunos.nome);
  
  printf("Digite o cpf do(a) aluno(a): ");
  gets(alunos.cpf);
  ajustCpf(alunos.cpf);
  fprintf(fp, "%s,",alunos.cpf);
  
  printf("Digite o telefone do(a) aluno(a): ");
  gets(alunos.telefone);
  ajustTel(alunos.telefone);
  fprintf(fp, "%s,",alunos.telefone);

  printf("Digite o email do(a) aluno(a): ");
  gets(alunos.email);
  fprintf(fp, "%s",alunos.email);

  fprintf(fp, "\n");

  fclose(fp);

  limparTela();
  printf("Cadastro finalizado com sucesso!!\n\nPressione enter para continuar");
  getchar();
}
// Função para cadastrar os professores
void cadastrarProfessor(){
  char c;
  FILE *fp;
  struct professores professores;
  limparTela();
  fp = fopen("professores.csv","a");
  verificarFile(fp);
  
  printf("Digite o ID do(a) professor(a): ");
  scanf("%d",&professores.professor_id);
  fprintf(fp, "%d,",professores.professor_id);
  
  limparLixo(c);
  
  printf("Digite o nome do(a) professor(a): ");
  gets(professores.nome);
  fprintf(fp, "%s,",professores.nome);
  
  printf("Digite o cpf do(a) professor(a): ");
  gets(professores.cpf);
  ajustCpf(professores.cpf);
  fprintf(fp, "%s,",professores.cpf);
  
  printf("Digite o telefone do(a) professor(a): ");
  gets(professores.telefone);
  ajustTel(professores.telefone);
  fprintf(fp, "%s,",professores.telefone);

  printf("Digite o email do(a) professor(a): ");
  gets(professores.email);
  fprintf(fp, "%s",professores.email);

  fprintf(fp, "\n");

  fclose(fp);

  limparTela();
  printf("Cadastro finalizado com sucesso!!\n\nPressione enter para continuar");
  getchar();
}
// Função para cadastrar as turmas
void cadastrarTurma(){
  char c,linha[100],stringTemporaria[100],*idTok;
  const char delimitador[] = ",";
  int encontrado = 0;
  FILE *fp;
  struct turmas aulas;
  limparTela();
  fp = fopen("turmas.csv","r+");
  verificarFile(fp);

  printf("Digite o ID da turma: ");
  scanf("%d",&aulas.turma_id);

  // Codigo de verificação de existencia de ID
  sprintf(stringTemporaria,"%d",aulas.turma_id);
  while (fgets(linha, sizeof(linha), fp) != NULL) {
    linha[strcspn(linha, "\n")] = '\0';
    idTok = strtok(linha,delimitador);
    if(strcmp(stringTemporaria,idTok) == 0){
      encontrado = 1;
    }
  }
  
  if(encontrado){
    limparLixo(c);
    limparTela();
    printf("ID ja cadastrado, tente novamente");
    getchar();
  }
  else{
    fprintf(fp, "%d,",aulas.turma_id);
  
    printf("Digite o tipo da turma (A, B, C ou D): ");
    scanf(" %c",&aulas.tipo);
    fprintf(fp, "%c,",aulas.tipo);
  
    printf("Digite o dia (1 - Dom, ..., 7 - Sab): ");
    scanf("%d",&aulas.dia);
    fprintf(fp, "%d,",aulas.dia);
  
    limparLixo(c);
  
    printf("Digite o horário da aula (XX:XX): ");
    gets(&aulas.horario);
    fprintf(fp, "%s,",aulas.horario);
  
    printf("Digite o ID do(a) professor(a): ");
    scanf("%d",&aulas.id_professor);
    fprintf(fp, "%d,",aulas.id_professor);
  
    printf("Digite o numero máximo de alunos(as): ");
    scanf("%d",&aulas.maximo_aluno);
    fprintf(fp, "%d,",aulas.maximo_aluno);
    
    printf("Digite o numero minimo de alunos(as): ");
    scanf("%d",&aulas.minimo_aluno);
    fprintf(fp, "%d,",aulas.minimo_aluno);
  
    limparLixo(c);
  
    printf("Digite a faixa etária da aula (XX-XX): ");
    gets(&aulas.faixa_etaria);
    fprintf(fp, "%s",aulas.faixa_etaria);
  
    fprintf(fp, "\n");
    
    fclose(fp);
  
    limparTela();
    printf("Cadastro finalizado com sucesso!!\n\nPressione enter para continuar");
    getchar();
  }
}
// Função para inscrever alunos nas turmas
void inscreverAluno(){
  char c,linha[1024],stringTemporaria[100],*idTok;
  const char delimitador[] = ",";
  int encontrado = 0,idTurmaInicial=0,indiceEncontrado=-1,maiorIndice = -1,j = 0,maxAlunos = 0,id_aulaRef = 0;
  FILE *fp,*fpTurmas,*fpIndice,*fpId_aula,*fpQtdAlunoPorAula,*fpAulasCanceladas,*fpInscricoesCanceladas;
  struct inscricoes inscricoes[100];
  limparTela();
  fp = fopen("inscricoes.csv","r");
  verificarFile(fp);
  int primeiroCaractere = getc(fp);
  fclose(fp);
  
  fpTurmas = fopen("turmas.csv","r");
  verificarFile(fpTurmas);

  fpIndice = fopen("indice.txt","r");
  verificarFile(fpIndice);
  fscanf(fpIndice,"%d",&maiorIndice);
  fclose(fpIndice);
  
  printf("Digite o ID da aula: ");
  scanf("%d",&idTurmaInicial);
  
  // Verifica se o arquivo tem algum conteudo, se não tiver vai resetar os vetores do struct inscricoes, os arquivos auxiliares e os arquivos de relatorio
  if(primeiroCaractere == EOF){
    memset(inscricoes, 0, sizeof(inscricoes));
    maiorIndice = -1;
    fpId_aula = fopen("id_aula.txt","w");
    verificarFile(fpId_aula);
    fclose(fpId_aula);
    fpQtdAlunoPorAula = fopen("qtdAlunoPorAula.txt","w");
    verificarFile(fpQtdAlunoPorAula);
    fclose(fpQtdAlunoPorAula);
    fpAulasCanceladas = fopen("r_aulasCanceladas.csv","w");
    verificarFile(fpAulasCanceladas);
    fclose(fpAulasCanceladas);
    fpInscricoesCanceladas = fopen("r_inscricoesCanceladas.csv","w");
    verificarFile(fpInscricoesCanceladas);
    fclose(fpInscricoesCanceladas);
  }

  fp = fopen("inscricoes.csv","a");
  verificarFile(fp);

  // Verifica se o ID inserido pelo usuario existe no arquivo
  sprintf(stringTemporaria,"%d",idTurmaInicial);
  while (fgets(linha, sizeof(linha), fpTurmas) != NULL) {
    linha[strcspn(linha, "\n")] = '\0';
    idTok = strtok(linha,delimitador);
    if(strcmp(stringTemporaria,idTok) == 0){
      encontrado = 1;
    }
  }
  fclose(fpTurmas);

  
  if(encontrado){

    // Preenchendo vetor inscrições com dados do aqrquivo id_aula.txt
    fpId_aula = fopen("id_aula.txt","r");
    verificarFile(fpId_aula);
    fgets(linha, sizeof(linha), fpId_aula);
    fclose(fpId_aula);
    idTok = strtok(linha, ",");
    while (idTok != NULL) {
      inscricoes[j].id_aula = atoi(idTok);
      j++;
      idTok = strtok(NULL, ",");
    }

    j=0;

    // Preenchendo vetor inscrições com dados do aqrquivo qtdAlunoPorAula.txt
    fpQtdAlunoPorAula = fopen("qtdAlunoPorAula.txt","r");
    verificarFile(fpQtdAlunoPorAula);
    fgets(linha, sizeof(linha), fpQtdAlunoPorAula);
    fclose(fpQtdAlunoPorAula);
    idTok = strtok(linha, ",");
    while (idTok != NULL) {
      inscricoes[j].qtdAlunoPorAula = atoi(idTok);
      j++;
      idTok = strtok(NULL, ",");
    }

    //por conta de um erro que a gente não soube resolver esse bloco de codigo preenche os valores restantes do vetor com 0
    for(int i = maiorIndice+1;i<100;i++){
      inscricoes[i].id_aula = 0;
      inscricoes[i].qtdAlunoPorAula = 0;
    }
    //procura o indice do id da aula
    for(int i = 0;i<100;i++){
      if(idTurmaInicial == inscricoes[i].id_aula){
        indiceEncontrado = i;
        break;
      }
    }
    //procura pelo indice do primeiro valor nulu (valor que seja = 0)
    if(indiceEncontrado == -1){
      for(int i = 0;i<100;i++){
        if(inscricoes[i].id_aula == 0){
          indiceEncontrado = i;
          break;
        }
      }
    }

    //vai substituir a variavel maiorIndice pelo o encontrado e guardar esse indice no arquivo txt
    if(indiceEncontrado>maiorIndice){
      maiorIndice = indiceEncontrado;
      fpIndice = fopen("indice.txt","w");
      verificarFile(fpIndice);
      fprintf(fpIndice,"%d",maiorIndice);
      fclose(fpIndice);
    }
    
    // Verifica quantos alunos estao inscritos nas aulas
    fpTurmas = fopen("turmas.csv","r");
    verificarFile(fpTurmas);
    while(fgets(linha, sizeof(linha), fpTurmas)){
      sscanf(linha, "%d", &id_aulaRef);
      if(id_aulaRef == idTurmaInicial){
        sscanf(linha, "%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%d", &maxAlunos);
        if(inscricoes[indiceEncontrado].qtdAlunoPorAula+1 > maxAlunos){
          printf("\nEssa aula está lotada, tente outra aula");
          exit(1);
        }
      }
    }
    fclose(fpTurmas);
    
    
    inscricoes[indiceEncontrado].qtdAlunoPorAula++;
    inscricoes[indiceEncontrado].id_aula = idTurmaInicial;
    
    printf("Digite o ID do(a) aluno(a): ");
    scanf("%d",&inscricoes[indiceEncontrado].id_aluno);
    fprintf(fp,"%d,",inscricoes[indiceEncontrado].id_aluno);

    fprintf(fp,"%d",inscricoes[indiceEncontrado].id_aula);

    fpId_aula = fopen("id_aula.txt","w");
    verificarFile(fpId_aula);
    fpQtdAlunoPorAula = fopen("qtdAlunoPorAula.txt","w");
    verificarFile(fpQtdAlunoPorAula);
    for(int i = 0;i<100;i++){
      fprintf(fpId_aula,"%d,",inscricoes[i].id_aula);
      fprintf(fpQtdAlunoPorAula,"%d,",inscricoes[i].qtdAlunoPorAula);
    }
    fclose(fpId_aula);
    fclose(fpQtdAlunoPorAula);
    
    fprintf(fp,"\n");

    printf("\nAlunos inscritos nesta aula: %d\n",inscricoes[indiceEncontrado].qtdAlunoPorAula);
    getchar();
    
    fclose(fp);
  
    limparLixo(c);
    
    limparTela();
    printf("Cadastro finalizado com sucesso!!\n\nPressione enter para continuar");
    getchar();
  }
  else{
    limparTela();
    limparLixo(c);
    printf("aula não encontrada! tente novamente.");
    getchar();
  }
  
}
// Função para canclar inscrições dos alunos nas turmas
void cancelarInscricao(){
  struct inscricoes inscricoesCanceladas;
  FILE *fp,*fpCancel,*fpTemp;
  char c, linha[100], stringTemporaria[100];
  limparTela();
  fp = fopen("inscricoes.csv","r+");
  verificarFile(fp);
  fpCancel = fopen("r_inscricoesCanceladas.csv","a");
  verificarFile(fpCancel);
  fpTemp = fopen("temp.csv","w");
  verificarFile(fpTemp);

  printf("Digite o ID do(a) aluno(a): ");
  scanf("%d",&inscricoesCanceladas.id_aluno);
  
  printf("Digite o ID da aula: ");
  scanf("%d",&inscricoesCanceladas.id_aula);

  sprintf(stringTemporaria,"%d,%d", inscricoesCanceladas.id_aluno,inscricoesCanceladas.id_aula);

  int encontrado = 0;
  
  while (fgets(linha, sizeof(linha), fp) != NULL) {
    linha[strcspn(linha, "\n")] = '\0';
    if(strcmp(stringTemporaria,linha) == 0){
      encontrado = 1;
    }
  }

  if(encontrado){
    while (fgets(linha, sizeof(linha), fp) != NULL) {
      linha[strcspn(linha, "\n")] = '\0';
      if(strcmp(stringTemporaria,linha) == 0){
        fprintf(fpCancel,"%s\n",linha);
      }
      if(strcmp(stringTemporaria,linha) != 0){
        fprintf(fpTemp,"%s\n", linha);
      }
    }
  } else{
    limparTela();
    printf("ID do aluno ou aula não encontrado, por favor tente novamente.");
    getchar();
  }
  
  rewind(fp);

  while (fgets(linha, sizeof(linha), fp) != NULL) {
    linha[strcspn(linha, "\n")] = '\0';
    if (strcmp(stringTemporaria, linha) == 0) {
      fprintf(fpCancel, "%s\n", linha);
    } else {
      fprintf(fpTemp, "%s\n", linha);
    }
  }
   
  rename("inscricoes.csv","tempR.csv");
  rename("temp.csv", "inscricoes.csv");
  rename("tempR.csv","temp.csv");
  
  fprintf(fp,"\n");

  fclose(fp);
  fclose(fpCancel);
  fclose(fpTemp);
  
  limparLixo(c);

  if(encontrado){
    limparTela();
    printf("Cancelamento realizado com sucesso!!\n\nPressione enter para continuar");
    getchar();
  }
}
// Função para fechar as turmas
void fecharTurmas(){
  FILE *fp,*fpId_aula,*fpQtdAlunoPorAula,*fpTemp,*fpAulasCanceladas;
  int qtdAlunosFecharTurma = 0,j=0,idAulaRemover=0,idComp=0;
  char c,linha[100],stringTemporaria[100],*idTok;
  struct inscricoes inscricoes[100];
  limparTela();

  fp = fopen("turmas.csv","r+");
  verificarFile(fp);
  fpTemp = fopen("temp.csv","w");
  verificarFile(fpTemp);
  fpAulasCanceladas = fopen("r_aulasCanceladas.csv","a");
  verificarFile(fpAulasCanceladas);

  // Preenchendo vetor inscrições com dados do aqrquivo id_aula.txt
  fpId_aula = fopen("id_aula.txt","r");
  verificarFile(fpId_aula);
  fgets(linha, sizeof(linha), fpId_aula);
  fclose(fpId_aula);
  idTok = strtok(linha, ",");
  while (idTok != NULL) {
    inscricoes[j].id_aula = atoi(idTok);
    j++;
    idTok = strtok(NULL, ",");
  }

  j=0;

  // Preenchendo vetor inscrições com dados do aqrquivo qtdAlunoPorAula.txt
  fpQtdAlunoPorAula = fopen("qtdAlunoPorAula.txt","r");
  verificarFile(fpQtdAlunoPorAula);
  fgets(linha, sizeof(linha), fpQtdAlunoPorAula);
  fclose(fpQtdAlunoPorAula);
  idTok = strtok(linha, ",");
  while (idTok != NULL) {
    inscricoes[j].qtdAlunoPorAula = atoi(idTok);
    j++;
    idTok = strtok(NULL, ",");
  }

  
  printf("Digite a quantidade de alunos para fechar as turmas: ");
  scanf("%d",&qtdAlunosFecharTurma);

  // Preenchendo um arquivo temporario com as linhas que tiverem o numero de alunos maior que o inserido pelo usuario
  for(int i = 0;i<100;i++){
    if(inscricoes[i].qtdAlunoPorAula<qtdAlunosFecharTurma){
      idAulaRemover = inscricoes[i].id_aula;
      while(fgets(linha, sizeof(linha), fp) != NULL){
        sscanf(linha, "%d,", &idComp);
        if(idAulaRemover != idComp){
          fprintf(fpTemp,"%s",linha);
        }
        else{
          fprintf(fpAulasCanceladas,"%s",linha);
        }
      }
    }
  }
  
  // Renomeando os arquivos
  rename("turmas.csv", "tempR.csv");
  rename("temp.csv", "turmas.csv");
  rename("tempR.csv", "temp.csv");

  fclose(fp);
  fclose(fpTemp);
  fclose(fpAulasCanceladas);

  limparTela();
  printf("Turma Fechadas!");
  getchar();
  getchar();
}
// Função para confirmar as turmas
void confirmarTurmas(){
  FILE *fp,*fpQtdAlunoPorAula,*fpId_aula,*fpTemp,*fpInscricoes,*fpTemp2,*fpAulasCanceladas,*fpInscricoesCanceladas;
  int qtdAlunosFecharTurma = 0,j=0,idAulaRemover=0,idComp=0,alunoMin=0,idInscricoesRemover=0;
  char c,linha[100],stringTemporaria[100],*idTok,linha2[100];
  struct inscricoes inscricoes[100];

  fp = fopen("turmas.csv","r+");
  verificarFile(fp);

  fpTemp = fopen("temp.csv","w");
  verificarFile(fpTemp);

  fpInscricoes = fopen("inscricoes.csv","r+");
  verificarFile(fpInscricoes);

  fpTemp2 = fopen("temp2.csv","w");
  verificarFile(fpTemp2);

  fpAulasCanceladas = fopen("r_aulasCanceladas.csv","a");
  verificarFile(fpAulasCanceladas);

  fpInscricoesCanceladas = fopen("r_inscricoesCanceladas.csv","a");
  verificarFile(fpInscricoesCanceladas);

  // Preenchendo vetor inscrições com dados do aqrquivo id_aula.txt
  fpId_aula = fopen("id_aula.txt","r");
  verificarFile(fpId_aula);
  fgets(linha, sizeof(linha), fpId_aula);
  fclose(fpId_aula);
  idTok = strtok(linha, ",");
  while (idTok != NULL) {
    inscricoes[j].id_aula = atoi(idTok);
    j++;
    idTok = strtok(NULL, ",");
  }

  j=0;

  // Preenchendo vetor inscrições com dados do aqrquivo qtdAlunoPorAula.txt
  fpQtdAlunoPorAula = fopen("qtdAlunoPorAula.txt","r");
  verificarFile(fpQtdAlunoPorAula);
  fgets(linha, sizeof(linha), fpQtdAlunoPorAula);
  fclose(fpQtdAlunoPorAula);
  idTok = strtok(linha, ",");
  while (idTok != NULL) {
    inscricoes[j].qtdAlunoPorAula = atoi(idTok);
    j++;
    idTok = strtok(NULL, ",");
  }

  // Lendo os arquivos e colocando os dados corretos nos arquivos temporarios
  for(int i = 0;i<100;i++){
    fseek(fp, 0, SEEK_SET);
    fseek(fpInscricoes, 0, SEEK_SET);
    while(fgets(linha, sizeof(linha), fp) != NULL){
      sscanf(linha, "%d,", &idComp);
      if(inscricoes[i].id_aula == idComp){
        sscanf(linha, "%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%d", &alunoMin);
        if(inscricoes[i].qtdAlunoPorAula>=alunoMin){
          fprintf(fpTemp,"%s",linha);
        }
        else{
          fprintf(fpAulasCanceladas,"%s",linha);
          while(fgets(linha2, sizeof(linha), fpInscricoes) != NULL){
            sscanf(linha2, "%*[^,],%d", &idInscricoesRemover);
            if(idInscricoesRemover != idComp){
              fprintf(fpTemp2,"%s",linha2);
            }
            else{
              fprintf(fpInscricoesCanceladas,"%s",linha2);
            }
          }
        }
      }
    }
  }


  // Renomeando os arquivos
  rename("turmas.csv", "tempR.csv");
  rename("temp.csv", "turmas.csv");
  rename("tempR.csv", "temp.csv");

  rename("inscricoes.csv", "tempR.csv");
  rename("temp2.csv", "inscricoes.csv");
  rename("tempR.csv", "temp2.csv");
  

  fclose(fpTemp2);
  fclose(fpInscricoes);
  fclose(fpTemp);
  fclose(fp);
  fclose(fpAulasCanceladas);
  fclose(fpInscricoesCanceladas);

  limparTela();
  printf("As aulas com os requisitos necessários foram confirmadas, as demais foram canceladas.");
  getchar();
  getchar();
}