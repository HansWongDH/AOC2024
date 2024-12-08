import java.io.FileReader;
import java.util.ArrayList;

import java.io.BufferedReader;
import java.io.IOException;
import java.util.List;
import java.util.*;

public class Aoc {

    public static void main(String[] args) {
        int sum = 0;

        try (BufferedReader br = new BufferedReader(new FileReader("day2.txt"))) {
            String line;

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

    public static boolean parseReport(List<Integer> integerList) {
        if (isValid(integerList)) {
            return true;
        }

        for (int i = 0; i < integerList.size(); i++) {
            List<Integer> modifiedList = new ArrayList<>(integerList);
            modifiedList.remove(i);
            if (isValid(modifiedList)) {
                return true;
            }
        }

        return false; 
    }


    public static boolean isValid(List<Integer> integerList) {
        int isIncreasing = 0; 

        for (int i = 0; i < integerList.size() - 1; i++) {
            int diff = Math.abs(integerList.get(i) - integerList.get(i + 1));
            if (diff < 1 || diff > 3) {  
                return false;
            }

            if (isIncreasing == 0) {
                isIncreasing = integerList.get(i + 1) - integerList.get(i);
            } else if (isIncreasing > 0 != (integerList.get(i) < integerList.get(i + 1))) {
                return false;  
            }
        }
        return true;
    }
}
