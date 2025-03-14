'''https://www.codewars.com/kata/514a024011ea4fb54200004b
5 kyu
'''

def domain_name(url):
    url = url.split('//')[-1].split('.')
    url.remove('www') if 'www' in url else ''
    return url[0]