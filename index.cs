using System;
using System.Text.RegularExpressions;
					
public class Program
{
	public static bool CheckIDNP(string idnp)
	{
		if (string.IsNullOrEmpty(idnp)) return false;

		Regex r = new Regex(@"\d{13}");
		Match match = r.Match(idnp);

		if (!match.Success) return false;

		char[] charIdnp = idnp.ToCharArray();

		int intSum1 = 0, intSum2 = 0, intSum3 = 0;
		for (int i = 0; i < idnp.Length - 1; i = i + 3)
		{
            intSum1 += Convert.ToInt32(charIdnp[i].ToString());
            intSum2 += Convert.ToInt32(charIdnp[i + 1].ToString());
            intSum3 += Convert.ToInt32(charIdnp[i + 2].ToString());
		}

		return idnp.EndsWith(((intSum1 * 7 + intSum2 * 3 + intSum3) % 10).ToString());
	}

	public static void Main()
	{
		string idnp = "1234567891234";

		bool idnpValid = CheckIDNP(idnp);

		if(idnpValid) {	Console.WriteLine("Valid IDNP"); }else{ Console.WriteLine("Not a valid IDNP"); }
	}
}