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

    public static boolean parseReport(List<Integer> integerList) {
        // Check if the report is valid without removing any element
        if (isValid(integerList)) {
            return true;
        }

        // Otherwise, check if removing one element makes it valid
        for (int i = 0; i < integerList.size(); i++) {
            List<Integer> modifiedList = new ArrayList<>(integerList);
            modifiedList.remove(i); // Remove the element at index i
            if (isValid(modifiedList)) {
                return true;
            }
        }

        return false;  // If neither case is valid, return false
    }

    // Check if the list is valid based on the difference between consecutive elements
    public static boolean isValid(List<Integer> integerList) {
        int isIncreasing = 0;  // To track if the sequence is increasing or decreasing

        for (int i = 0; i < integerList.size() - 1; i++) {
            int diff = Math.abs(integerList.get(i) - integerList.get(i + 1));
            if (diff < 1 || diff > 3) {  // Invalid if difference is less than 1 or greater than 3
                return false;
            }

            // Track the direction (increasing or decreasing)
            if (isIncreasing == 0) {
                isIncreasing = integerList.get(i + 1) - integerList.get(i);
            } else if (isIncreasing > 0 != (integerList.get(i) < integerList.get(i + 1))) {
                return false;  // If the direction changes, it's invalid
            }
        }
        return true;  // All differences ar
    }
}
