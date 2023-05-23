import java.util.regex.*;

public class Main {
    public static boolean checkIDNP(String idnp) {
        if (idnp == null || idnp.isEmpty())
            return false;

        Pattern pattern = Pattern.compile("\\d{13}");
        Matcher matcher = pattern.matcher(idnp);

        if (!matcher.matches())
            return false;

        char[] charIdnp = idnp.toCharArray();

        int intSum1 = 0, intSum2 = 0, intSum3 = 0;
        for (int i = 0; i < idnp.length() - 1; i += 3) {
            intSum1 += Character.getNumericValue(charIdnp[i]);
            intSum2 += Character.getNumericValue(charIdnp[i + 1]);
            intSum3 += Character.getNumericValue(charIdnp[i + 2]);
        }

        return idnp.endsWith(String.valueOf((intSum1 * 7 + intSum2 * 3 + intSum3) % 10));
    }

    public static void main(String[] args) {
        String idnp = "1234567891234";

        boolean idnpValid = checkIDNP(idnp);

        if (idnpValid)
            System.out.println("Valid IDNP");
        else
            System.out.println("Not a valid IDNP");
    }
}