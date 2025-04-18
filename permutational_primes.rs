use std::collections::HashSet;

fn permutational_primes(n_max: u32, k_perms: u32) -> (u32, u32, u32) {
    let primes = sieve(n_max);
    let set: HashSet<u32> = primes.iter().cloned().collect();
    
    let mut processed = HashSet::new();
    let mut result = Vec::new();
    
    for &p in &primes {
        if processed.contains(&p) {
            continue;
        }
        
        let digits = p.to_string().chars().collect::<Vec<char>>();
        let mut perm = HashSet::new();
        generate_permutations(&digits, &mut perm, 0);
        
        let mut prime_perms: Vec<u32> = perm
            .iter()
            .filter_map(|s| {
                if s.starts_with('0') { return None; }
                let num = s.parse::<u32>().unwrap();
                if num != p && set.contains(&num) { Some(num) } else { None }
            })
            .collect();
        
        prime_perms.sort();
        
        if prime_perms.len() as u32 == k_perms {
            result.push(p);
            processed.insert(p);
            for perm in &prime_perms {
                processed.insert(*perm);
            }
        }
    }
    
    result.sort();
    
    if result.is_empty() {
        (0, 0, 0)
    } else {
        (
            result.len() as u32,
            *result.first().unwrap(),
            *result.last().unwrap(),
        )
    }
}

fn sieve(n: u32) -> Vec<u32> {
    if n < 2 {
        return vec![];
    }
    
    let mut sieve = vec![true; (n + 1) as usize];
    sieve[0] = false;
    sieve[1] = false;
    
    for i in 2..=(n as f64).sqrt() as u32 {
        if sieve[i as usize] {
            for j in (i*i..=n).step_by(i as usize) {
                sieve[j as usize] = false;
            }
        }
    }
    
    sieve.iter()
        .enumerate()
        .filter(|(_, &is_prime)| is_prime)
        .map(|(i, _)| i as u32)
        .collect()
}

fn generate_permutations(digits: &[char], permutations: &mut HashSet<String>, start: usize) {
    if start == digits.len() {
        permutations.insert(digits.iter().collect());
        return;
    }
    
    for i in start..digits.len() {
        let mut digits = digits.to_vec();
        digits.swap(start, i);
        generate_permutations(&digits, permutations, start + 1);
    }
}