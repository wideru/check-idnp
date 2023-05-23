function check(idnp: string): boolean {
  if (idnp.length === 0) {
    return false;
  }

  const reg = /\d{13}/;

  if (!reg.test(idnp)) {
    return false;
  }

  let intSum1 = 0;
  let intSum2 = 0;
  let intSum3 = 0;

  for (let i = 0; i < idnp.length - 1; i += 3) {
    intSum1 += Number(idnp[i]);
    intSum2 += Number(idnp[i + 1]);
    intSum3 += Number(idnp[i + 2]);
  }

  const checkSum = (intSum1 * 7 + intSum2 * 3 + intSum3) % 10;

  return idnp.endsWith(checkSum.toString());
}