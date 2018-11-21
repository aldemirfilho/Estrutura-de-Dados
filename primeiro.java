-------------------priemiro.java---------------------
package Folha;

import java.util.HashMap;
import java.util.Scanner;

public class Primeiro 
{
	public static void main(String[] args)
	{
		for(int i = 0; i < 0; ++i) 
		{
			System.out.println();
		}
		
		 Scanner input = new Scanner(System.in);
		
		System.out.println("            Bem vindo ao sistema de folha de pagamento!!!");
		System.out.println();
		System.out.println("Digite a opção de qual função deseja execultar...");
		System.out.println();
		System.out.println("1 . Adição de um empregado");
		System.out.println("2 . Remoção de um empregado");
		System.out.println("3 . Lançar um Cartão de Ponto");
		System.out.println("4 . Lançar um Resultado Venda");
		System.out.println("5 . Lançar uma taxa de serviço");
		System.out.println("6 . Alterar detalhes de um empregado");
		System.out.println("7 . Rodar a folha de pagamento para hoje");
		System.out.println("8 . Undo/redo");
		System.out.println("9 . Agenda de Pagamento");
		System.out.println("10 . Criação de Novas Agendas de Pagamento");
		System.out.println();
		System.out.print("Opção:");
		
		int opcao;
		opcao = input.nextInt();
		
		int cont = 0;
		int id;
		
		if(opcao == 1)
		{
			cont++;
			
			java.util.ArrayList<Admin> admins_nome = new java.util.ArrayList<Admin>(); 
			System.out.println();
			
			Admin admin_nome = new Admin( );
			
			System.out.println("Digite o nome do empregado:");
			admin_nome.name = input.nextLine();
			admins_nome.add(admin_nome);
			
			//-----------------------------------------------------------------------
			
			java.util.ArrayList<Admin> admins_endereco = new java.util.ArrayList<Admin>(); 
			System.out.println();
			
			Admin admin_endereco = new Admin( );
			
			System.out.println("Digite o endereço do empregado:");
			admin_endereco.name = input.nextLine();
			admins_endereco.add(admin_endereco);
			
			//-----------------------------------------------------------------------
			
			java.util.ArrayList<Admin> admins_tipo = new java.util.ArrayList<Admin>(); 
			System.out.println();
			
			Admin admin_tipo = new Admin( );
			
			System.out.println("Digite o tipo de recebimento do empregado:");
			admin_tipo.name = input.nextLine();
			admins_tipo.add(admin_tipo);
			
			//-----------------------------------------------------------------------
			
			java.util.ArrayList<Admin> admins_valor = new java.util.ArrayList<Admin>(); 
			System.out.println();
			
			Admin admin_valor = new Admin( );
			
			System.out.println("Digite o tipo de recebimento do empregado:");
			admin_valor.name = input.nextLine();
			admins_valor.add(admin_valor);
			
			//-----------------------------------------------------------------------
			id = cont;
		}
		if(opcao == 2)
		{
			
		}
		if(opcao == 3)
		{
			System.out.println("Insira seu id, para marcar presença...");
			int meu_id = input.nextInt();
			int tam = 1000000;
			int[] presenca = new int[tam];
			presenca[meu_id] = 1;
			System.out.println("Presença registrada com sucesso.");
		}
	}

}

----------------------------segundo----------------------
