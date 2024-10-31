package p1tarea1rodriguezbrigitte;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class P1Tarea1RodriguezBrigitte {
    // Variables para las calificaciones y promedios
    private static float Rodriguez_nota1, Rodriguez_nota2, Rodriguez_nota3, Rodriguez_promedio;
    private static int Rodriguez_num, Rodriguez_opcion;
    private static String registros = ""; // Cadena para almacenar promedios

    // Funcion para registrar notas
    private static void Rodriguez_registrarNotas(int personaIndex) {
        Scanner scanner = new Scanner(System.in);

        // Solicitar y validar las calificaciones
        Rodriguez_nota1 = obtenerNota(scanner, 1);
        Rodriguez_nota2 = obtenerNota(scanner, 2);
        Rodriguez_nota3 = obtenerNota(scanner, 3);

        // Calcular el promedio
        Rodriguez_promedio = (Rodriguez_nota1 + Rodriguez_nota2 + Rodriguez_nota3) / 3;
        registros += "Persona " + personaIndex + ": " + Rodriguez_promedio + "\n"; // Almacenar el promedio

        System.out.println("Su promedio es de: " + Rodriguez_promedio);
        System.out.println(Rodriguez_promedio > 14 ? "Usted aprobo el curso" : "Usted reprobo el curso");

        // Guardar notas en archivos
        Rodriguez_guardarNotas(personaIndex);
    }

    private static float obtenerNota(Scanner scanner, int calificacionNumero) {
        float nota;
        do {
            System.out.print("Ingrese su calificacion " + calificacionNumero + " (0-20): ");
            nota = scanner.nextFloat();
        } while (nota < 0 || nota > 20);
        return nota;
    }

    // Funcion para guardar notas en archivos JSON y CSV
    private static void Rodriguez_guardarNotas(int personaIndex) {
        // Guardar en JSON
        String jsonString = "{\n" +
                "    \"Persona\": " + personaIndex + ",\n" +
                "    \"Calificacion 1\": " + Rodriguez_nota1 + ",\n" +
                "    \"Calificacion 2\": " + Rodriguez_nota2 + ",\n" +
                "    \"Calificacion 3\": " + Rodriguez_nota3 + ",\n" +
                "    \"Promedio\": " + Rodriguez_promedio + "\n" +
                "},\n";

        try (BufferedWriter jsonFile = new BufferedWriter(new FileWriter("Registro_de_notas.json", true))) {
            jsonFile.write(jsonString);
            System.out.println("Sus calificaciones han sido guardadas en Registro_de_notas.json");
        } catch (IOException e) {
            System.out.println("No se logro abrir el archivo JSON, error: " + e.getMessage());
        }

        // Guardar en CSV
        try (BufferedWriter csvFile = new BufferedWriter(new FileWriter("Registro_de_notas.csv", true))) {
            if (personaIndex == 1) {
                csvFile.write("Persona,Calificacion 1,Calificacion 2,Calificacion 3,Promedio\n");
            }
            csvFile.write(personaIndex + "," + Rodriguez_nota1 + "," + Rodriguez_nota2 + "," + Rodriguez_nota3 + "," + Rodriguez_promedio + "\n");
            System.out.println("Sus calificaciones han sido guardadas en Registro_de_notas.csv");
        } catch (IOException e) {
            System.out.println("No se logro abrir el archivo CSV, error: " + e.getMessage());
        }
    }

    // Funcion para mostrar el menu 
    private static void Rodriguez_menu() {
        do {
            System.out.println("----------------------------------");
            System.out.println("Bienvenido al menu de opciones: ");
            System.out.println("1. Registrar notas");
            System.out.println("2. Ver promedios");
            System.out.println("3. Salir");
            System.out.print("Seleccione una opcion: ");

            Scanner scanner = new Scanner(System.in);
            Rodriguez_opcion = scanner.nextInt();

            switch (Rodriguez_opcion) {
                case 1:
                    System.out.print("Cuantas personas desea ingresar? (1-5): ");
                    Rodriguez_num = scanner.nextInt();

                    // Validar que el numero de personas este entre 1 y 5
                    while (Rodriguez_num < 1 || Rodriguez_num > 5) {
                        System.out.print("El limite de personas es 1 a 5, ingrese nuevamente: ");
                        Rodriguez_num = scanner.nextInt();
                    }

                    for (int i = 1; i <= Rodriguez_num; i++) {
                        Rodriguez_registrarNotas(i);
                    }
                    break;
                case 2:
                    System.out.println("Promedios registrados:");
                    System.out.print(registros); // Mostrar todos los promedios registrados
                    break;
                case 3:
                    System.out.println("Gracias por usar el programa");
                    break;
                default:
                    System.out.println("Incorrecto, ingrese nuevamente");
            }
        } while (Rodriguez_opcion != 3);
    }

    // Funcion principal del programa
    public static void main(String[] args) {
        Rodriguez_menu(); // Llamar al menu
    }
}