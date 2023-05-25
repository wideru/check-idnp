<?php

class CheckIDNP
{
    public static function check(string $idnp): bool
    {
        $match = preg_match('/\d{13}/', $idnp);

        if (!$match) return false;

        $intSum1 = $intSum2 = $intSum3 = 0;

        for ($i = 0; $i < strlen($idnp) - 1; $i = $i + 3) {
            $intSum1 += $idnp[$i];
            $intSum2 += $idnp[$i + 1];
            $intSum3 += $idnp[$i + 2];
        }

        return str_ends_with($idnp, ($intSum1 * 7 + $intSum2 * 3 + $intSum3) % 10);
    }
}
