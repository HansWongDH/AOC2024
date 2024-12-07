import java.io.FileReader;
import java.util.ArrayList;

import java.io.BufferedReader;
import java.io.IOException;
import java.util.List;

public class Aoc {

    public static void main(String[] args) {
        int sum = 0;

        try (BufferedReader br = new BufferedReader(new FileReader("day2.txt"))) {
            String line;

            // Loop through each line in the file
            while ((line = br.readLine()) != null) {
                sum += parseReport(parseLine(line)) ? 1 : 0;
            }
            System.out.println(sum);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static List<Integer> parseLine(String line) {
        String[] input = line.split(" ");
        List<Integer> subList = new ArrayList<>();

        for (String element : input) {
            subList.add(Integer.parseInt(element));
        }
        return subList;
    }

    public static boolean parseReport(List<Integer> lists) {
        int ascOrDec =  lists.get(0) - lists.get(1);

        for (int i = 0; i < lists.size() - 1; i++) {
            int x = lists.get(i) - lists.get(i + 1);
            if (Math.abs(x) < 1 || Math.abs(x) > 3) {
                return false;
            }
            if ((ascOrDec > 0 && x < 0) || (ascOrDec < 0 && x > 0)) {
                return false;
            }
        }
        return true;
    }
}
