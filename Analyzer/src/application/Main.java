package application;

import java.io.File;
import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.printf("Digite o nome do diretório e do arquivo\nExemplo: './Files/nomeArquivo'");
		String str = input.next(); 
		ReadFile reader = new ReadFile(new File(str));
		reader.read();
		reader.result();
		
	}
}
