using System;
class ex1
{
    static void Main()
    {
        // Definindo o tamanho do vetor

        // Criando o vetor
        int[] vetor = new int[10];
        int maior = vetor[0];
        int menor = vetor[0];

        Console.WriteLine("Digite 5 valores: ");
        
        Random random = new Random();

        for (int i = 0; i < vetor.Length; i++)
        {
            vetor[i] = random.Next(5);
            int controle = vetor[i];

            if (controle > maior)
            {
                maior = controle;
            }
            if (controle < menor)
            {
                menor = controle;
            }
        }
        Console.WriteLine("O maior número é: " + maior);
        Console.WriteLine("O menor número é: " + menor);

    }
}
