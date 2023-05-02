import java.util.*;

public class Code_gen {
    private static boolean isInequality(String exp) {
        return exp.contains(">") || exp.contains("<");
    }

    private static void readExp(String exp) {
        String subExp = exp.substring(exp.indexOf("=") + 1);
        int temp_count = 1;
        String replace;
        while (subExp.length() != 0) {
            if (subExp.contains("*") && subExp.contains("/")) {
                if (subExp.indexOf("*") < subExp.indexOf("/")) {
                    replace = getVariable(subExp.charAt(subExp.indexOf("") - 1), subExp, 0) + ""
                            + getVariable(subExp.charAt(subExp.indexOf("") + 1), subExp, subExp.indexOf("") + 1);
                    System.out.println("temp" + temp_count + "=" + replace);
                    subExp = subExp.replace(replace, "temp" + temp_count);
                } else if (subExp.indexOf("*") > subExp.indexOf("/")) {
                    replace = getVariable(subExp.charAt(subExp.indexOf("/") - 1), subExp, 0) + "/"
                            + getVariable(subExp.charAt(subExp.indexOf("/") + 1), subExp, subExp.indexOf("/") + 1);
                    System.out.println("temp" + temp_count + "=" + replace);
                    subExp = subExp.replace(replace, "temp" + temp_count);
                }
                temp_count += 1;
                continue;
            }
            if (subExp.contains("*")) {
                replace = getVariable(subExp.charAt(subExp.indexOf("") - 1), subExp, 0) + ""
                        + getVariable(subExp.charAt(subExp.indexOf("") + 1), subExp, subExp.indexOf("") + 1);
                System.out.println("temp" + temp_count + "=" + replace);
                subExp = subExp.replace(replace, "temp" + temp_count);
                temp_count += 1;
                continue;
            }
            if (subExp.contains("/")) {
                replace = getVariable(subExp.charAt(subExp.indexOf("/") - 1), subExp, 0) + "/"
                        + getVariable(subExp.charAt(subExp.indexOf("/") + 1), subExp, subExp.indexOf("/") + 1);
                System.out.println("temp" + temp_count + "=" + replace);
                subExp = subExp.replace(replace, "temp" + temp_count);
                temp_count += 1;
                continue;
            }
            if (subExp.contains("+") && subExp.contains("-")) {
                if (subExp.indexOf("+") < subExp.indexOf("-")) {
                    replace = getVariable(subExp.charAt(subExp.indexOf("+") - 1), subExp, 0) + "+"
                            + getVariable(subExp.charAt(subExp.indexOf("+") + 1), subExp, subExp.indexOf("+") + 1);
                    System.out.println("temp" + temp_count + "=" + replace);
                    subExp = subExp.replace(replace, "temp" + temp_count);
                } else if (subExp.indexOf("+") > subExp.indexOf("-")) {
                    replace = getVariable(subExp.charAt(subExp.indexOf("-") - 1), subExp, 0) + "-"
                            + getVariable(subExp.charAt(subExp.indexOf("-") + 1), subExp, subExp.indexOf("-") + 1);
                    System.out.println("temp" + temp_count + "=" + replace);
                    subExp = subExp.replace(replace, "temp" + temp_count);
                }
                temp_count += 1;
                continue;
            }
            if (subExp.contains("+")) {
                replace = getVariable(subExp.charAt(subExp.indexOf("+") - 1), subExp, 0) + "+"
                        + getVariable(subExp.charAt(subExp.indexOf("+") + 1), subExp, subExp.indexOf("+") + 1);
                System.out.println("temp" + temp_count + "=" + replace);
                subExp = subExp.replace(replace, "temp" + temp_count);
                temp_count += 1;
                continue;
            }
            if (subExp.contains("-")) {
                replace = getVariable(subExp.charAt(subExp.indexOf("-") - 1), subExp, 0) + "-"
                        + getVariable(subExp.charAt(subExp.indexOf("-") + 1), subExp, subExp.indexOf("-") + 1);
                System.out.println("temp" + temp_count + "=" + replace);
                subExp = subExp.replace(replace, "temp" + temp_count);
                temp_count += 1;
                continue;
            }
            if (subExp.equals("temp" + (temp_count - 1))) {
                subExp = "";
            }
        }
        System.out.println(exp.charAt(0) + "=" + "temp" + (temp_count - 1));
    }

    private static String getVariable(char ch, String exp, int i) {
        if (ch == 't') {
            return "temp" + exp.charAt(i + 4);
        }
        if ((int) ch >= 97 && (int) ch <= 122) {
            return String.valueOf(ch);
        }
        return "temp" + ch;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter an expression: ");
        String exp = sc.next();
        if (isInequality(exp)) {
            System.out.println("100: if " + exp + " goto 103");
            System.out.println("101: T=0");
            System.out.println("102: goto 104");
            System.out.println("103: T=1");
            System.out.println("104: ");
        } else {
            readExp(exp);
        }
    }
}